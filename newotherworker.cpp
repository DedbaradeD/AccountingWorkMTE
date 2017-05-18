#include "newotherworker.h"
#include "ui_newotherworker.h"
#include "otherworkers.h"
#include <QSqlQuery>

NewOtherWorker::NewOtherWorker(OtherWorkers *otherWorkers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOtherWorker)
{
    ui->setupUi(this);
    m_pOtherWorkers = otherWorkers;
}

NewOtherWorker::~NewOtherWorker()
{
    delete ui;
}

void NewOtherWorker::clearDataFormNewOtherWorker()
{
    ui->personalNumber->clear();
    ui->lastName->clear();
    ui->name->clear();
    ui->middleName->clear();
    ui->passportSeries->clear();
    ui->passportNumber->clear();
    ui->post->clear();
}

void NewOtherWorker::addNewOtherWorker()
{
    QSqlQuery querySetDataOtherWorkers;
    querySetDataOtherWorkers.prepare("INSERT INTO OtherWorkers(idOtherWorker, personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, post) "
                                     "VALUES(?, ?, ?, ?, ?, ?, ?, ?)");
    int count = m_pOtherWorkers->searchRowCountOtherWorkers();
    querySetDataOtherWorkers.addBindValue(count);
    querySetDataOtherWorkers.addBindValue(ui->personalNumber->text());
    querySetDataOtherWorkers.addBindValue(ui->lastName->text());
    querySetDataOtherWorkers.addBindValue(ui->name->text());
    querySetDataOtherWorkers.addBindValue(ui->middleName->text());
    querySetDataOtherWorkers.addBindValue(ui->dateOfBirth->date());
    querySetDataOtherWorkers.addBindValue(ui->passportSeries->text() + ui->passportNumber->text());
    querySetDataOtherWorkers.addBindValue(ui->post->text());
    querySetDataOtherWorkers.exec();

    m_pOtherWorkers->addTableRowOtherWorkers(count);
    this->clearDataFormNewOtherWorker();
    this->close();
}
