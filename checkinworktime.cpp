#include "checkinworktime.h"
#include "ui_checkinworktime.h"
#include <QSqlQuery>

CheckInWorkTime::CheckInWorkTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckInWorkTime)
{
    ui->setupUi(this);

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
            ui->worker->addItem(queryGetDataOtherWorkers.value(0).toString()+ " " + str1[0] + "." + str2[0] + ".");
        }
    }
}

CheckInWorkTime::~CheckInWorkTime()
{
    delete ui;
}

int CheckInWorkTime::searchRowCountEmployedOtherWorkers()
{
    int count;
    QSqlQuery queryGetCountEmployedOtherWorkers;
    queryGetCountEmployedOtherWorkers.exec("SELECT COUNT(*) FROM EmployedOtherWorkers");
    while (queryGetCountEmployedOtherWorkers.next())
    {
        count = queryGetCountEmployedOtherWorkers.value(0).toInt();
    }
    return count;
}

void CheckInWorkTime::addWorkTime()
{
    QSqlQuery querySetDataEmployedOtherWorkers;
    querySetDataEmployedOtherWorkers.prepare("INSERT INTO EmployedOtherWorkers(idEmployedOtherWorker, date, idOtherWorker, timeWorked, shift) "
                                        "VALUES(?, ?, ?, ?, ?)");
    int count = this->searchRowCountEmployedOtherWorkers();
    querySetDataEmployedOtherWorkers.addBindValue(count);
    querySetDataEmployedOtherWorkers.addBindValue(ui->date->date());
    querySetDataEmployedOtherWorkers.addBindValue(ui->worker->lineEdit()->text());
    int allTimeInSeconds = ui->beginWork->time().secsTo(ui->endWork->time());
    //int allTimeInMinute = allTimeInSeconds / 60;
    //int temp = allTimeInMinute;
    //int resultHours;
    //while (temp % 60 != 0)
    //{
        //temp--;
        //if (temp % 60 == 0)
            //resultHours = temp / 60;
    //}
    //int resultMinute = allTimeInMinute - temp;
    //char hours = resultHours;
    //char minute = resultMinute;
    //querySetDataEmployedOtherWorkers.addBindValue(hours + "ч." + minute + "мин.");
    querySetDataEmployedOtherWorkers.addBindValue(allTimeInSeconds / 3600);
    querySetDataEmployedOtherWorkers.addBindValue(ui->shift->text());
    querySetDataEmployedOtherWorkers.exec();

    this->close();
}
