#include "newdriver.h"
#include "ui_newdriver.h"
#include "drivers.h"
#include <QSqlQuery>

NewDriver::NewDriver(Drivers *driver, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDriver)
{
    ui->setupUi(this);
    m_pDrivers = driver;

    int counter;
    QSqlQuery queryGetCountMotorTransport;
    queryGetCountMotorTransport.exec("SELECT COUNT(*) FROM MotorTransport");
    while (queryGetCountMotorTransport.next())
    {
        counter = queryGetCountMotorTransport.value(0).toInt();
    }
    for (int i = 0; i < counter; i++)
    {
        QSqlQuery queryGetDataMotorTransport;
        queryGetDataMotorTransport.prepare("SELECT brand, stateNumber FROM MotorTransport WHERE idMotorTransport = :rowCount");
        queryGetDataMotorTransport.bindValue(":rowCount", i);
        queryGetDataMotorTransport.exec();
        while (queryGetDataMotorTransport.next())
        {
            ui->brand->addItem(queryGetDataMotorTransport.value(0).toString()+ " " + "(" + queryGetDataMotorTransport.value(1).toString() + ")");
        }
    }
}

NewDriver::~NewDriver()
{
    delete ui;
}

void NewDriver::clearDataFormNewDriver()
{
    ui->personalNumber->clear();
    ui->lastName->clear();
    ui->name->clear();
    ui->middleName->clear();
    ui->passportSeries->clear();
    ui->passportNumber->clear();
    ui->driversLicenceSeries->clear();
    ui->driversLicenceNumber->clear();
}

void NewDriver::addNewDriver()
{
    QSqlQuery querySetDataDrivers;
    querySetDataDrivers.prepare("INSERT INTO Drivers(idDriver, personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, driversLicence, idMotorTransport) "
                                "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)");
    int count = m_pDrivers->searchRowCountDrivers();
    querySetDataDrivers.addBindValue(count);
    querySetDataDrivers.addBindValue(ui->personalNumber->text());
    querySetDataDrivers.addBindValue(ui->lastName->text());
    querySetDataDrivers.addBindValue(ui->name->text());
    querySetDataDrivers.addBindValue(ui->middleName->text());
    querySetDataDrivers.addBindValue(ui->dateOfBirth->date());
    querySetDataDrivers.addBindValue(ui->passportSeries->text() + ui->passportNumber->text());
    querySetDataDrivers.addBindValue(ui->driversLicenceSeries->text() + ui->driversLicenceNumber->text());
    querySetDataDrivers.addBindValue(ui->brand->lineEdit()->text());
    querySetDataDrivers.exec();

    m_pDrivers->addTableRowDrivers(count);
    this->clearDataFormNewDriver();
    this->close();
}
