#include "searchemployeddrivers.h"
#include "ui_searchemployeddrivers.h"
#include "employeddrivers.h"
#include <QLineEdit>
#include <QSqlQuery>

SearchEmployedDrivers::SearchEmployedDrivers(EmployedDrivers *employedDrivers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchEmployedDrivers)
{
    ui->setupUi(this);
    m_pEmployedDrivers = employedDrivers;
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

SearchEmployedDrivers::~SearchEmployedDrivers()
{
    delete ui;
}

void SearchEmployedDrivers::checkBoxClicked()
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

void SearchEmployedDrivers::showSearchResult()
{
    QSqlQuery queryGetDataEmployedDrivers;
    queryGetDataEmployedDrivers.prepare("SELECT date, idDriver, workedTime, "
                                        "idRoute, shift, exitOnLine, "
                                        "scheduledFlights, actualFlights, mileage, "
                                        "idMotorTransport, reserve, downTime, "
                                        "repair, TI2 FROM TravelSheet "
                                        "WHERE date >= :dateFrom AND date <= :dateTo AND idDriver = :driver");
    if (m_period) {
        queryGetDataEmployedDrivers.bindValue(":dateFrom", ui->dateFrom->date());
        queryGetDataEmployedDrivers.bindValue(":dateTo", ui->dateTo->date());
    } else {
        queryGetDataEmployedDrivers.bindValue(":dateFrom", ui->date->date());
        queryGetDataEmployedDrivers.bindValue(":dateTo", ui->date->date());
    }
    queryGetDataEmployedDrivers.bindValue(":driver", ui->drivers->lineEdit()->text());
    queryGetDataEmployedDrivers.exec();
    QString arrayDataEmployedDrivers[14];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataEmployedDrivers.next())
    {
        for (int i = 0; i < 14; i++)
            arrayDataEmployedDrivers[i] = queryGetDataEmployedDrivers.value(i).toString();

        m_pEmployedDrivers->addTableWidgetRows(counter, arrayDataEmployedDrivers);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        m_pEmployedDrivers->addTableWidgetRows(-1, arrayDataEmployedDrivers);

    this->close();
}
