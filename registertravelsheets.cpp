#include "registertravelsheets.h"
#include "ui_registertravelsheets.h"
#include <QLineEdit>
#include <QSqlQuery>

RegisterTravelSheets::RegisterTravelSheets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterTravelSheets)
{
    ui->setupUi(this);

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

RegisterTravelSheets::~RegisterTravelSheets()
{
    delete ui;
}

void RegisterTravelSheets::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}

void RegisterTravelSheets::showSearchResult()
{
    QSqlQuery queryGetDataTravelSheets;
    queryGetDataTravelSheets.prepare("SELECT numberSheet, date, idDriver, "
                                     "actualExit, actualReturn, speedometerExit, "
                                     "speedometerReturn, spendFuelExit, "
                                     "spendFuelReturn, actualFlights "
                                     "FROM TravelSheet "
                                     "WHERE date >= :dateFrom AND date <= :dateTo AND idDriver = :driver");
    queryGetDataTravelSheets.bindValue(":dateFrom", ui->dateFrom->date());
    queryGetDataTravelSheets.bindValue(":dateTo", ui->dateTo->date());
    queryGetDataTravelSheets.bindValue(":driver", ui->drivers->lineEdit()->text());
    queryGetDataTravelSheets.exec();
    QString arrayDataRegisterTravelSheets[10];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataTravelSheets.next())
    {
        for (int i = 0; i < 10; i++)
            arrayDataRegisterTravelSheets[i] = queryGetDataTravelSheets.value(i).toString();

        this->addTableWidgetRows(counter, arrayDataRegisterTravelSheets);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        this->addTableWidgetRows(-1, arrayDataRegisterTravelSheets);
}
