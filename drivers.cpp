#include "drivers.h"
#include "ui_drivers.h"
#include "newdriver.h"
#include <QSqlQuery>

Drivers::Drivers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Drivers)
{
    ui->setupUi(this);
    m_pNewDriver = new NewDriver(this);

    m_rowCountDrivers = this->searchRowCountDrivers();
    ui->tableWidget->setRowCount(m_rowCountDrivers);

    QSqlQuery queryShowDataDrivers;
    queryShowDataDrivers.exec("SELECT personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, driversLicence, idMotorTransport "
                              "FROM Drivers");
    queryShowDataDrivers.next();
    for (int i = 0; i < m_rowCountDrivers; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryShowDataDrivers.value(j).toString()).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
        queryShowDataDrivers.next();
    }
}

Drivers::~Drivers()
{
    delete ui;
    delete m_pNewDriver;
}

int Drivers::searchRowCountDrivers()
{
    int count;
    QSqlQuery queryGetCountDrivers;
    queryGetCountDrivers.exec("SELECT COUNT(*) FROM Drivers");
    while (queryGetCountDrivers.next())
    {
        count = queryGetCountDrivers.value(0).toInt();
    }
    return count;
}

void Drivers::showNewDriverForm()
{
    m_pNewDriver->show();
}

void Drivers::addTableRowDrivers(int count)
{
    ui->tableWidget->setRowCount(count + 1);
    QSqlQuery queryGetDataDrivers;
    queryGetDataDrivers.prepare("SELECT personalNumber, lastName, name, middleName, dateOfBirth, passportNumber, driversLicence, idMotorTransport "
                                "FROM Drivers "
                                "WHERE idDriver = :rowCount");
    queryGetDataDrivers.bindValue(":rowCount", count);
    queryGetDataDrivers.exec();
    while (queryGetDataDrivers.next())
    {
        for (int j = 0; j < 8; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryGetDataDrivers.value(j).toString()).arg(count).arg(j));
            ui->tableWidget->setItem(count, j, pItem);
        }
    }
}

void Drivers::removeDriver()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();

    while (!selectedRows.empty())
    {
        ui->tableWidget->removeRow(selectedRows[0].row());

        QSqlQuery queryRemoveDataDrivers;
        queryRemoveDataDrivers.prepare("DELETE FROM Drivers WHERE idDriver = :driver");
        queryRemoveDataDrivers.bindValue(":driver", selectedRows[0].row());
        queryRemoveDataDrivers.exec();

        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}
