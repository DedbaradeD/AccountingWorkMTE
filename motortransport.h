#ifndef MOTORTRANSPORT_H
#define MOTORTRANSPORT_H

#include <QMainWindow>

class NewMotorTransport;

namespace Ui {
class MotorTransport;
}

class MotorTransport : public QMainWindow
{
    Q_OBJECT

public:
    explicit MotorTransport(QWidget *parent = 0);
    ~MotorTransport();

    void addTableRowMotorTransport(int count);
    int searchRowCountMotorTransport();

private slots:
    void showNewMotorTransportForm();
    void removeMotorTransport();

private:
    Ui::MotorTransport *ui;
    NewMotorTransport *m_pNewMotorTransport;
    int m_rowCountMotorTransport;
};

#endif // MOTORTRANSPORT_H
