#include "summarylogbybrand.h"
#include "ui_summarylogbybrand.h"
#include <QLineEdit>
#include <QSqlQuery>

SummaryLogByBrand::SummaryLogByBrand(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SummaryLogByBrand)
{
    ui->setupUi(this);
}

SummaryLogByBrand::~SummaryLogByBrand()
{
    delete ui;
}

void SummaryLogByBrand::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}

void SummaryLogByBrand::showSearchResult()
{
    QSqlQuery queryGetDataTravelSheets;
    queryGetDataTravelSheets.prepare("SELECT idMotorTransport, date, idRoute, "
                                     "workedTime, mileage, spendFuel "
                                     "FROM TravelSheet "
                                     "WHERE date >= :dateFrom AND date <= :dateTo");
    queryGetDataTravelSheets.bindValue(":dateFrom", ui->dateFrom->date());
    queryGetDataTravelSheets.bindValue(":dateTo", ui->dateTo->date());
    queryGetDataTravelSheets.exec();
    QString arrayDataRegisterTravelSheets[6];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataTravelSheets.next())
    {
        for (int i = 0; i < 6; i++)
            arrayDataRegisterTravelSheets[i] = queryGetDataTravelSheets.value(i).toString();

        this->addTableWidgetRows(counter, arrayDataRegisterTravelSheets);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        this->addTableWidgetRows(-1, arrayDataRegisterTravelSheets);
}
