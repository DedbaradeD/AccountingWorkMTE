#include "motortransport.h"
#include "ui_motortransport.h"
#include "newmotortransport.h"
#include <QTableWidgetItem>
#include <QSqlQuery>

MotorTransport::MotorTransport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MotorTransport)
{
    ui->setupUi(this);
    m_pNewMotorTransport = new NewMotorTransport(this);
    m_rowCountMotorTransport = this->searchRowCountMotorTransport();
    ui->tableWidget->setRowCount(m_rowCountMotorTransport);
    QSqlQuery queryShowData;
    queryShowData.exec("SELECT brand, stateNumber, speedometer FROM MotorTransport");
    queryShowData.next();
    for (int i = 0; i < m_rowCountMotorTransport; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryShowData.value(j).toString()).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
        queryShowData.next();
    }
}

MotorTransport::~MotorTransport()
{
    delete ui;
    delete m_pNewMotorTransport;
}

int MotorTransport::searchRowCountMotorTransport()
{
    int count;
    QSqlQuery queryGetCountMotorTransport;
    queryGetCountMotorTransport.exec("SELECT COUNT(*) FROM MotorTransport");
    while (queryGetCountMotorTransport.next())
    {
        count = queryGetCountMotorTransport.value(0).toInt();
    }
    return count;
}

void MotorTransport::showNewMotorTransportForm()
{
    m_pNewMotorTransport->show();
}

void MotorTransport::addTableRowMotorTransport(int count)
{
    ui->tableWidget->setRowCount(count + 1);
    QSqlQuery queryGetData;
    queryGetData.prepare("SELECT brand, stateNumber, speedometer FROM MotorTransport WHERE idMotorTransport = :rowCount");
    queryGetData.bindValue(":rowCount", count);
    queryGetData.exec();
    while (queryGetData.next())
    {
        for (int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryGetData.value(j).toString()).arg(count).arg(j));
            ui->tableWidget->setItem(count, j, pItem);
        }
    }
}

void MotorTransport::removeMotorTransport()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();

    while (!selectedRows.empty())
    {
        ui->tableWidget->removeRow(selectedRows[0].row());

        QSqlQuery queryRemoveDataMotorTransport;
        queryRemoveDataMotorTransport.prepare("DELETE FROM MotorTransport WHERE idMotorTransport = :motorTransport");
        queryRemoveDataMotorTransport.bindValue(":motorTransport", selectedRows[0].row());
        queryRemoveDataMotorTransport.exec();

        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}
