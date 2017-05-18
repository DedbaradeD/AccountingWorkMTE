#include "searchtravelsheets.h"
#include "ui_searchtravelsheets.h"
#include "travelsheets.h"
#include <QLineEdit>
#include <QSqlQuery>

SearchTravelSheets::SearchTravelSheets(TravelSheets *travelSheets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchTravelSheets)
{
    ui->setupUi(this);
    m_pTravelSheets = travelSheets;
    m_period = false;

    int counter;
    QSqlQuery queryGetCountDrivers;
    queryGetCountDrivers.exec("SELECT COUNT(*) FROM Drivers");
    while (queryGetCountDrivers.next())
    {
        counter = queryGetCountDrivers.value(0).toInt();
    }
    for (int i = 0; i < counter; i++)
    {
        QSqlQuery queryGetDataDrivers;
        queryGetDataDrivers.prepare("SELECT lastName, name, middleName FROM Drivers WHERE idDriver = :rowCount");
        queryGetDataDrivers.bindValue(":rowCount", i);
        queryGetDataDrivers.exec();
        while (queryGetDataDrivers.next())
        {
            QString str1 = queryGetDataDrivers.value(1).toString();
            QString str2 = queryGetDataDrivers.value(2).toString();
            ui->drivers->addItem(queryGetDataDrivers.value(0).toString()+ " " + str1[0] + "." + str2[0] + ".");
        }
    }
}

SearchTravelSheets::~SearchTravelSheets()
{
    delete ui;
}

void SearchTravelSheets::checkBoxClicked()
{
    if (ui->checkBox->isChecked()) {
        ui->dateLabel->setEnabled(false);
        ui->date->setEnabled(false);
        ui->groupBox->setEnabled(true);
        m_period = true;
    } else {
        ui->dateLabel->setEnabled(true);
        ui->date->setEnabled(true);
        ui->groupBox->setEnabled(false);
        m_period = false;
    }
}

void SearchTravelSheets::showSearchResult()
{
    QSqlQuery queryGetDataTravelSheets;
    queryGetDataTravelSheets.prepare("SELECT numberSheet, idDriver, idMotorTransport "
                                     "FROM TravelSheet "
                                     "WHERE date >= :dateFrom AND date <= :dateTo AND idDriver = :driver");
    if (m_period) {
        queryGetDataTravelSheets.bindValue(":dateFrom", ui->dateFrom->date());
        queryGetDataTravelSheets.bindValue(":dateTo", ui->dateTo->date());
    } else {
        queryGetDataTravelSheets.bindValue(":dateFrom", ui->date->date());
        queryGetDataTravelSheets.bindValue(":dateTo", ui->date->date());
    }
    queryGetDataTravelSheets.bindValue(":driver", ui->drivers->lineEdit()->text());
    queryGetDataTravelSheets.exec();
    QString arrayDataEmployedDrivers[3];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataTravelSheets.next())
    {
        for (int i = 0; i < 3; i++)
            arrayDataEmployedDrivers[i] = queryGetDataTravelSheets.value(i).toString();

        m_pTravelSheets->addTableWidgetRows(counter, arrayDataEmployedDrivers);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        m_pTravelSheets->addTableWidgetRows(-1, arrayDataEmployedDrivers);

    this->close();
}
