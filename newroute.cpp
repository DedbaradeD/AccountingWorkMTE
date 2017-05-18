#include "newroute.h"
#include "ui_newroute.h"
#include "routes.h"
#include <QSqlQuery>

NewRoute::NewRoute(Routes *routes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRoute)
{
    ui->setupUi(this);
    m_pRoutes = routes;
}

NewRoute::~NewRoute()
{
    delete ui;
}

void NewRoute::clearDataFormNewRoute()
{
    ui->nameRoute->clear();
    ui->direction->clear();
    ui->distance->clear();
    ui->flights->clear();
    ui->fuel->clear();
}

void NewRoute::addNewRoute()
{
    QSqlQuery querySetDataRoutes;
    querySetDataRoutes.prepare("INSERT INTO Routes(idRoute, nameRoute, direction, distance, flights, fuel, exitTime, returnTime) "
                               "VALUES(?, ?, ?, ?, ?, ?, ?, ?)");
    int count = m_pRoutes->searchRowCountRoutes();
    querySetDataRoutes.addBindValue(count);
    querySetDataRoutes.addBindValue(ui->nameRoute->text());
    querySetDataRoutes.addBindValue(ui->direction->text());
    querySetDataRoutes.addBindValue(ui->distance->text());
    querySetDataRoutes.addBindValue(ui->flights->text());
    querySetDataRoutes.addBindValue(ui->fuel->text());
    querySetDataRoutes.addBindValue(ui->exitTime->time());
    querySetDataRoutes.addBindValue(ui->returnTime->time());
    querySetDataRoutes.exec();

    m_pRoutes->addTableRowRoutes(count);
    this->clearDataFormNewRoute();
    this->close();
}
