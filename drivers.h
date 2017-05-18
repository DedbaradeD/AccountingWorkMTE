#ifndef DRIVERS_H
#define DRIVERS_H

#include <QMainWindow>

class NewDriver;

namespace Ui {
class Drivers;
}

class Drivers : public QMainWindow
{
    Q_OBJECT

public:
    explicit Drivers(QWidget *parent = 0);
    ~Drivers();

    void addTableRowDrivers(int count);
    int searchRowCountDrivers();

private slots:
    void showNewDriverForm();
    void removeDriver();

private:
    Ui::Drivers *ui;
    NewDriver *m_pNewDriver;
    int m_rowCountDrivers;
};

#endif // DRIVERS_H
