#ifndef NEWDRIVER_H
#define NEWDRIVER_H

#include <QDialog>

class Drivers;

namespace Ui {
class NewDriver;
}

class NewDriver : public QDialog
{
    Q_OBJECT

public:
    explicit NewDriver(Drivers *drivers, QWidget *parent = 0);
    ~NewDriver();
    void clearDataFormNewDriver();

private slots:
    void addNewDriver();

private:
    Ui::NewDriver *ui;
    Drivers *m_pDrivers;
};

#endif // NEWDRIVER_H
