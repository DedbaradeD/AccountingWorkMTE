#include "routes.h"
#include "ui_routes.h"
#include "newroute.h"
#include <QSqlQuery>

Routes::Routes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Routes)
{
    ui->setupUi(this);
    m_pNewRoute = new NewRoute(this);
    m_rowCountRoutes = this->searchRowCountRoutes();

    ui->tableWidget->setRowCount(m_rowCountRoutes);

    QSqlQuery queryShowDataRoutes;
    queryShowDataRoutes.exec("SELECT nameRoute, direction, distance, flights, fuel, exitTime, returnTime "
                             "FROM Routes");
    queryShowDataRoutes.next();
    for (int i = 0; i < m_rowCountRoutes; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryShowDataRoutes.value(j).toString()).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
        queryShowDataRoutes.next();
    }
}

Routes::~Routes()
{
    delete ui;
    delete m_pNewRoute;
}

int Routes::searchRowCountRoutes()
{
    int count;
    QSqlQuery queryGetCountRoutes;
    queryGetCountRoutes.exec("SELECT COUNT(*) FROM Routes");
    while (queryGetCountRoutes.next())
    {
        count = queryGetCountRoutes.value(0).toInt();
    }
    return count;
}

void Routes::showNewRouteForm()
{
    m_pNewRoute->show();
}

void Routes::addTableRowRoutes(int count)
{
    ui->tableWidget->setRowCount(count + 1);
    QSqlQuery queryGetDataRoutes;
    queryGetDataRoutes.prepare("SELECT nameRoute, direction, distance, flights, fuel, exitTime, returnTime "
                                "FROM Routes "
                                "WHERE idRoute = :rowCount");
    queryGetDataRoutes.bindValue(":rowCount", count);
    queryGetDataRoutes.exec();
    while (queryGetDataRoutes.next())
    {
        for (int j = 0; j < 7; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(queryGetDataRoutes.value(j).toString()).arg(count).arg(j));
            ui->tableWidget->setItem(count, j, pItem);
        }
    }
}

void Routes::removeRoute()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();

    while (!selectedRows.empty())
    {
        ui->tableWidget->removeRow(selectedRows[0].row());

        QSqlQuery queryRemoveDataMotorTransport;
        queryRemoveDataMotorTransport.prepare("DELETE FROM Routes WHERE idRoute = :route");
        queryRemoveDataMotorTransport.bindValue(":route", selectedRows[0].row());
        queryRemoveDataMotorTransport.exec();

        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}
