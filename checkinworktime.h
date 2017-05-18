#ifndef CHECKINWORKTIME_H
#define CHECKINWORKTIME_H

#include <QDialog>

namespace Ui {
class CheckInWorkTime;
}

class CheckInWorkTime : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInWorkTime(QWidget *parent = 0);
    ~CheckInWorkTime();

    int searchRowCountEmployedOtherWorkers();

private slots:
    void addWorkTime();

private:
    Ui::CheckInWorkTime *ui;
};

#endif // CHECKINWORKTIME_H
