#ifndef NEWMOTORTRANSPORT_H
#define NEWMOTORTRANSPORT_H

#include <QDialog>

class MotorTransport;

namespace Ui {
class NewMotorTransport;
}

class NewMotorTransport : public QDialog
{
    Q_OBJECT

public:
    explicit NewMotorTransport(MotorTransport *motorTransport, QWidget *parent = 0);
    ~NewMotorTransport();
    void clearDataFormNewMotorTransport();

private slots:
    void addNewMotorTransport();

private:
    Ui::NewMotorTransport *ui;
    MotorTransport *m_pMotorTransport;
};

#endif // NEWMOTORTRANSPORT_H
