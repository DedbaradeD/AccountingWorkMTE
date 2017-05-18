#ifndef EMPLOYEDDRIVERS_H
#define EMPLOYEDDRIVERS_H

#include <QMainWindow>

class SearchEmployedDrivers;

namespace Ui {
class EmployedDrivers;
}

class EmployedDrivers : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployedDrivers(QWidget *parent = 0);
    ~EmployedDrivers();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchEmployedDriversForm();

private:
    Ui::EmployedDrivers *ui;
    SearchEmployedDrivers *m_pSearchEmployedDriversForm;
};

#endif // EMPLOYEDDRIVERS_H
