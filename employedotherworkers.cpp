#include "employedotherworkers.h"
#include "ui_employedotherworkers.h"
#include "searchemployedotherworker.h"

EmployedOtherWorkers::EmployedOtherWorkers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployedOtherWorkers)
{
    ui->setupUi(this);
    m_pSearchEmployedOtherWorkerForm = new SearchEmployedOtherWorker(this);
}

EmployedOtherWorkers::~EmployedOtherWorkers()
{
    delete ui;
    delete m_pSearchEmployedOtherWorkerForm;
}

void EmployedOtherWorkers::showSearchEmployedOtherWorkerForm()
{
    m_pSearchEmployedOtherWorkerForm->show();
}

void EmployedOtherWorkers::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}
