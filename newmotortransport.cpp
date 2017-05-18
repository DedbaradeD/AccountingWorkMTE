#include "newmotortransport.h"
#include "ui_newmotortransport.h"
#include "motortransport.h"
#include <QSqlQuery>

NewMotorTransport::NewMotorTransport(MotorTransport *motorTransport, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMotorTransport)
{
    ui->setupUi(this);
    m_pMotorTransport = motorTransport;
}

NewMotorTransport::~NewMotorTransport()
{
    delete ui;
}

void NewMotorTransport::clearDataFormNewMotorTransport()
{
    ui->brand->clear();
    ui->stateNumber->clear();
    ui->speedometer->clear();
}

void NewMotorTransport::addNewMotorTransport()
{
    QSqlQuery querySetData;
    querySetData.prepare("INSERT INTO MotorTransport(idMotorTransport, brand, stateNumber, speedometer) VALUES(?, ?, ?, ?)");
    int count = m_pMotorTransport->searchRowCountMotorTransport();
    querySetData.addBindValue(count);
    querySetData.addBindValue(ui->brand->text());
    querySetData.addBindValue(ui->stateNumber->text());
    querySetData.addBindValue(ui->speedometer->text());
    querySetData.exec();

    m_pMotorTransport->addTableRowMotorTransport(count);
    this->clearDataFormNewMotorTransport();
    this->close();
}
