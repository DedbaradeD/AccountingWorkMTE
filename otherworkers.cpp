#include "otherworkers.h"
#include "ui_otherworkers.h"
#include "newotherworker.h"
#include <QSqlQuery>

OtherWorkers::OtherWorkers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OtherWorkers)
{
    ui->setupUi(this);
    m_pNewOtherWorker = new NewOtherWorker(this);

    m_rowCountOtherWorkers = this->searchRowCountOtherWorkers();
    ui->tableWidget->setRowCount(m_rowCountOtherWorkers);

    QSqlQuery queryShowDataOtherWorkers;
    queryShowDataOtherWorkers.exec("SELECT personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, post "
                              "FROM OtherWorkers");
    queryShowDataOtherWorkers.next();
    for (int i = 0; i < m_rowCountOtherWorkers; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryShowDataOtherWorkers.value(j).toString()).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
        queryShowDataOtherWorkers.next();
    }
}

OtherWorkers::~OtherWorkers()
{
    delete ui;
    delete m_pNewOtherWorker;
}

int OtherWorkers::searchRowCountOtherWorkers()
{
    int count;
    QSqlQuery queryGetCountOtherWorkers;
    queryGetCountOtherWorkers.exec("SELECT COUNT(*) FROM OtherWorkers");
    while (queryGetCountOtherWorkers.next())
    {
        count = queryGetCountOtherWorkers.value(0).toInt();
    }
    return count;
}

void OtherWorkers::showNewOtherWorkerForm()
{
    m_pNewOtherWorker->show();
}

void OtherWorkers::addTableRowOtherWorkers(int count)
{
    ui->tableWidget->setRowCount(count + 1);
    QSqlQuery queryGetDataOtherWorkers;
    queryGetDataOtherWorkers.prepare("SELECT personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, post "
                                     "FROM OtherWorkers "
                                     "WHERE idOtherWorker = :rowCount");
    queryGetDataOtherWorkers.bindValue(":rowCount", count);
    queryGetDataOtherWorkers.exec();
    while (queryGetDataOtherWorkers.next())
    {
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryGetDataOtherWorkers.value(j).toString()).arg(count).arg(j));
            ui->tableWidget->setItem(count, j, pItem);
        }
    }
}

void OtherWorkers::removeOtherWorker()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();

    while (!selectedRows.empty())
    {
        ui->tableWidget->removeRow(selectedRows[0].row());

        QSqlQuery queryRemoveDataMotorTransport;
        queryRemoveDataMotorTransport.prepare("DELETE FROM OtherWorkers WHERE idOtherWorker = :otherWorker");
        queryRemoveDataMotorTransport.bindValue(":otherWorker", selectedRows[0].row());
        queryRemoveDataMotorTransport.exec();

        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}
