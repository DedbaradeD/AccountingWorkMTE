#ifndef EMPLOYEDOTHERWORKERS_H
#define EMPLOYEDOTHERWORKERS_H

#include <QMainWindow>

class SearchEmployedOtherWorker;

namespace Ui {
class EmployedOtherWorkers;
}

class EmployedOtherWorkers : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployedOtherWorkers(QWidget *parent = 0);
    ~EmployedOtherWorkers();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchEmployedOtherWorkerForm();

private:
    Ui::EmployedOtherWorkers *ui;
    SearchEmployedOtherWorker *m_pSearchEmployedOtherWorkerForm;
};

#endif // EMPLOYEDOTHERWORKERS_H
