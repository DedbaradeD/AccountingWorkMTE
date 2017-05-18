#include "searchemployedotherworker.h"
#include "ui_searchemployedotherworker.h"
#include "employedotherworkers.h"
#include <QLineEdit>
#include <QSqlQuery>

SearchEmployedOtherWorker::SearchEmployedOtherWorker(EmployedOtherWorkers *employedOtherWorkers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchEmployedOtherWorker)
{
    ui->setupUi(this);
    m_pEmployedOtherWorkers = employedOtherWorkers;
    m_period = false;

    int counter;
    QSqlQuery queryGetCountOtherWorkers;
    queryGetCountOtherWorkers.exec("SELECT COUNT(*) FROM OtherWorkers");
    while (queryGetCountOtherWorkers.next())
    {
        counter = queryGetCountOtherWorkers.value(0).toInt();
    }
    for (int i = 0; i < counter; i++)
    {
        QSqlQuery queryGetDataOtherWorkers;
        queryGetDataOtherWorkers.prepare("SELECT lastName, name, middleName FROM OtherWorkers WHERE idOtherWorker = :rowCount");
        queryGetDataOtherWorkers.bindValue(":rowCount", i);
        queryGetDataOtherWorkers.exec();
        while (queryGetDataOtherWorkers.next())
        {
            QString str1 = queryGetDataOtherWorkers.value(1).toString();
            QString str2 = queryGetDataOtherWorkers.value(2).toString();
            ui->comboBox->addItem(queryGetDataOtherWorkers.value(0).toString()+ " " + str1[0] + "." + str2[0] + ".");
        }
    }
}

SearchEmployedOtherWorker::~SearchEmployedOtherWorker()
{
    delete ui;
}

void SearchEmployedOtherWorker::checkBoxClicked()
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

void SearchEmployedOtherWorker::showSearchResult()
{
    QSqlQuery queryGetDataEmployedOtherWorkers;
    queryGetDataEmployedOtherWorkers.prepare("SELECT date, idOtherWorker, timeWorked, shift FROM EmployedOtherWorkers "
                                             "WHERE date >= :dateFrom AND date <= :dateTo AND idOtherWorker = :worker");
    if (m_period) {
        queryGetDataEmployedOtherWorkers.bindValue(":dateFrom", ui->dateFrom->date());
        queryGetDataEmployedOtherWorkers.bindValue(":dateTo", ui->dateTo->date());
    } else {
        queryGetDataEmployedOtherWorkers.bindValue(":dateFrom", ui->date->date());
        queryGetDataEmployedOtherWorkers.bindValue(":dateTo", ui->date->date());
    }
    queryGetDataEmployedOtherWorkers.bindValue(":worker", ui->comboBox->lineEdit()->text());
    queryGetDataEmployedOtherWorkers.exec();
    QString arrayDataEmployedOtherWorkers[4];
    int counter = 0;
    bool dateNoExist = true;
    while(queryGetDataEmployedOtherWorkers.next())
    {
        for (int i = 0; i < 4; i++)
            arrayDataEmployedOtherWorkers[i] = queryGetDataEmployedOtherWorkers.value(i).toString();

        m_pEmployedOtherWorkers->addTableWidgetRows(counter, arrayDataEmployedOtherWorkers);
        counter++;
        dateNoExist = false;
    }

    if (dateNoExist)
        m_pEmployedOtherWorkers->addTableWidgetRows(-1, arrayDataEmployedOtherWorkers);

    this->close();
}
