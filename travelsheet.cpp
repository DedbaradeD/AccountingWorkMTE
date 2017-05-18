#include "travelsheet.h"
#include "ui_travelsheet.h"
#include <QSqlQuery>

TravelSheet::TravelSheet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TravelSheet)
{
    ui->setupUi(this);
    m_downTime = false;

    int counterMotorTransport;
    QSqlQuery queryGetCountMotorTransport;
    queryGetCountMotorTransport.exec("SELECT COUNT(*) FROM MotorTransport");
    while (queryGetCountMotorTransport.next())
    {
        counterMotorTransport = queryGetCountMotorTransport.value(0).toInt();
    }
    for (int i = 0; i < counterMotorTransport; i++)
    {
        QSqlQuery queryGetDataMotorTransport;
        queryGetDataMotorTransport.prepare("SELECT brand, stateNumber FROM MotorTransport WHERE idMotorTransport = :rowCount");
        queryGetDataMotorTransport.bindValue(":rowCount", i);
        queryGetDataMotorTransport.exec();
        while (queryGetDataMotorTransport.next())
        {
            ui->motorTransport->addItem(queryGetDataMotorTransport.value(0).toString()+ " " + "(" + queryGetDataMotorTransport.value(1).toString() + ")");
        }
    }

    int counterDrivers;
    QSqlQuery queryGetCountDrivers;
    queryGetCountDrivers.exec("SELECT COUNT(*) FROM Drivers");
    while (queryGetCountDrivers.next())
    {
        counterDrivers = queryGetCountDrivers.value(0).toInt();
    }
    for (int i = 0; i < counterDrivers; i++)
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

    int counterRoutes;
    QSqlQuery queryGetCountRoutes;
    queryGetCountRoutes.exec("SELECT COUNT(*) FROM Routes");
    while (queryGetCountRoutes.next())
    {
        counterRoutes = queryGetCountRoutes.value(0).toInt();
    }
    for (int i = 0; i < counterRoutes; i++)
    {
        QSqlQuery queryGetDataRoutes;
        queryGetDataRoutes.prepare("SELECT nameRoute FROM Routes WHERE idRoute = :rowCount");
        queryGetDataRoutes.bindValue(":rowCount", i);
        queryGetDataRoutes.exec();
        while (queryGetDataRoutes.next())
        {
            ui->routes->addItem(queryGetDataRoutes.value(0).toString());
        }
    }
}

TravelSheet::~TravelSheet()
{
    delete ui;
}

void TravelSheet::checkBoxClicked()
{
    if (ui->checkBox->isChecked()) {
        ui->groupBoxDownTime->setEnabled(true);
        m_downTime = true;
    } else {
        ui->groupBoxDownTime->setEnabled(false);
        m_downTime = false;
    }
}

void TravelSheet::clearDataFormTravelSheet()
{
    ui->numberSheet->clear();
    ui->shift->clear();
    ui->exit->clear();
    ui->mileage->clear();
    ui->scheduledFlights->clear();
    ui->actualFlights->clear();
    ui->spendFuelExit->clear();
    ui->spendFuelReturn->clear();
    ui->repair->clear();
    ui->TI2->clear();
    ui->downTime->clear();
    ui->reserve->clear();
    ui->speedometerExit->clear();
    ui->speedometerReturn->clear();
}

void TravelSheet::addTravelSheet()
{
    QSqlQuery queryAddDataTravelSheet;
    queryAddDataTravelSheet.prepare("INSERT INTO TravelSheet(idTravelSheet, "
                                    "numberSheet, date, idMotorTransport, "
                                    "idDriver, idRoute, shift, exitOnLine, "
                                    "mileage, scheduledFlights, actualFlights, "
                                    "plannedExit, actualExit, plannedReturn, "
                                    "actualReturn, spendFuelExit, "
                                    "spendFuelReturn, repair, TI2, downTime, "
                                    "reserve, speedometerExit, speedometerReturn, "
                                    "workedTime, spendFuel) VALUES(?, ?, ?, ?, ?, "
                                    "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
                                    " ?, ?, ?, ?, ?, ?)");
    int count;
    QSqlQuery queryGetCountTravelSheet;
    queryGetCountTravelSheet.exec("SELECT COUNT(*) FROM TravelSheet");
    while (queryGetCountTravelSheet.next())
    {
        count = queryGetCountTravelSheet.value(0).toInt();
    }
    queryAddDataTravelSheet.addBindValue(count);
    queryAddDataTravelSheet.addBindValue(ui->numberSheet->text());
    queryAddDataTravelSheet.addBindValue(ui->date->date());
    queryAddDataTravelSheet.addBindValue(ui->motorTransport->lineEdit()->text());
    queryAddDataTravelSheet.addBindValue(ui->drivers->lineEdit()->text());
    queryAddDataTravelSheet.addBindValue(ui->routes->lineEdit()->text());
    queryAddDataTravelSheet.addBindValue(ui->shift->text());
    queryAddDataTravelSheet.addBindValue(ui->exit->text());
    queryAddDataTravelSheet.addBindValue(ui->mileage->text());
    queryAddDataTravelSheet.addBindValue(ui->scheduledFlights->text());
    queryAddDataTravelSheet.addBindValue(ui->actualFlights->text());
    queryAddDataTravelSheet.addBindValue(ui->plannedExit->text());
    queryAddDataTravelSheet.addBindValue(ui->actualExit->text());
    queryAddDataTravelSheet.addBindValue(ui->plannedReturn->text());
    queryAddDataTravelSheet.addBindValue(ui->actualReturn->text());
    queryAddDataTravelSheet.addBindValue(ui->spendFuelExit->text());
    queryAddDataTravelSheet.addBindValue(ui->spendFuelReturn->text());
    if (m_downTime) {
        queryAddDataTravelSheet.addBindValue(ui->repair->text());
        queryAddDataTravelSheet.addBindValue(ui->TI2->text());
        queryAddDataTravelSheet.addBindValue(ui->downTime->text());
    } else {
        queryAddDataTravelSheet.addBindValue("");
        queryAddDataTravelSheet.addBindValue("");
        queryAddDataTravelSheet.addBindValue("");
    }
    queryAddDataTravelSheet.addBindValue(ui->reserve->text());
    queryAddDataTravelSheet.addBindValue(ui->speedometerExit->text());
    queryAddDataTravelSheet.addBindValue(ui->speedometerReturn->text());
    int allTimeInSeconds = ui->actualExit->time().secsTo(ui->actualReturn->time());
    queryAddDataTravelSheet.addBindValue(allTimeInSeconds / 3600);
    queryAddDataTravelSheet.addBindValue((ui->spendFuelExit->text().toDouble()) - (ui->spendFuelReturn->text().toDouble()));
    queryAddDataTravelSheet.exec();

    this->clearDataFormTravelSheet();
    this->close();
}
