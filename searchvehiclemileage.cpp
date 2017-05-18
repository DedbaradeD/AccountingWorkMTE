#include "searchvehiclemileage.h"
#include "ui_searchvehiclemileage.h"
#include "vehiclesmileage.h"
#include <QLineEdit>
#include <QSqlQuery>

SearchVehicleMileage::SearchVehicleMileage(VehiclesMileage *vehiclesMileage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchVehicleMileage)
{
    ui->setupUi(this);
    m_pVehiclesMileage = vehiclesMileage;
    m_period = false;

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
            ui->motorTransport->addItem(queryGetDataMotorTransport.value(0).toString()+ " " + "(" + queryGetDataMotorTransport.value(1).toString() + ")");
        }
    }
}

SearchVehicleMileage::~SearchVehicleMileage()
{
    delete ui;
}

void SearchVehicleMileage::checkBoxClicked()
{
    if (ui->checkBox->isChecked()) {
        ui->dateLabel->setEnabled(false);
        ui->date->setEnabled(false);
        ui->groupBox->setEnabled(true);
        m_period = true;
    } else {
        ui->dateLabel->setEnabled(true);
        ui->date->setEnabled(true);
        ui->groupBox->setEnabled(false);
        m_period = false;
    }
}

void SearchVehicleMileage::showSearchResult()
{
    QSqlQuery queryGetDataVehiclesMileage;
    queryGetDataVehiclesMileage.prepare("SELECT idMotorTransport, date, mileage FROM TravelSheet "
                                        "WHERE date >= :dateFrom AND date <= :dateTo AND idMotorTransport = :motorTransport");
    if (m_period) {
        queryGetDataVehiclesMileage.bindValue(":dateFrom", ui->dateFrom->date());
        queryGetDataVehiclesMileage.bindValue(":dateTo", ui->dateTo->date());
    } else {
        queryGetDataVehiclesMileage.bindValue(":dateFrom", ui->date->date());
        queryGetDataVehiclesMileage.bindValue(":dateTo", ui->date->date());
    }
    queryGetDataVehiclesMileage.bindValue(":motorTransport", ui->motorTransport->lineEdit()->text());
    queryGetDataVehiclesMileage.exec();
    QString arrayDataVehiclesMileage[3];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataVehiclesMileage.next())
    {
        for (int i = 0; i < 3; i++)
            arrayDataVehiclesMileage[i] = queryGetDataVehiclesMileage.value(i).toString();

        m_pVehiclesMileage->addTableWidgetRows(counter, arrayDataVehiclesMileage);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        m_pVehiclesMileage->addTableWidgetRows(-1, arrayDataVehiclesMileage);

    this->close();
}
