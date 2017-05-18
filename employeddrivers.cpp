#include "employeddrivers.h"
#include "ui_employeddrivers.h"
#include "searchemployeddrivers.h"

EmployedDrivers::EmployedDrivers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployedDrivers)
{
    ui->setupUi(this);
    m_pSearchEmployedDriversForm = new SearchEmployedDrivers(this);
}

EmployedDrivers::~EmployedDrivers()
{
    delete ui;
    delete m_pSearchEmployedDriversForm;
}

void EmployedDrivers::showSearchEmployedDriversForm()
{
    m_pSearchEmployedDriversForm->show();
}

void EmployedDrivers::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}
