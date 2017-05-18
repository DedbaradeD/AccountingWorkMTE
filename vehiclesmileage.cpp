#include "vehiclesmileage.h"
#include "ui_vehiclesmileage.h"
#include "searchvehiclemileage.h"

VehiclesMileage::VehiclesMileage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VehiclesMileage)
{
    ui->setupUi(this);
    m_pSearchVehicleMileageForm = new SearchVehicleMileage(this);
}

VehiclesMileage::~VehiclesMileage()
{
    delete ui;
    delete m_pSearchVehicleMileageForm;
}

void VehiclesMileage::showSearchVehicleMileageForm()
{
    m_pSearchVehicleMileageForm->show();
}

void VehiclesMileage::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}
