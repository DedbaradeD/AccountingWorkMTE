#ifndef OTHERWORKERS_H
#define OTHERWORKERS_H

#include <QMainWindow>

class NewOtherWorker;

namespace Ui {
class OtherWorkers;
}

class OtherWorkers : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtherWorkers(QWidget *parent = 0);
    ~OtherWorkers();

    void addTableRowOtherWorkers(int count);
    int searchRowCountOtherWorkers();

private slots:
    void showNewOtherWorkerForm();
    void removeOtherWorker();

private:
    Ui::OtherWorkers *ui;
    NewOtherWorker *m_pNewOtherWorker;
    int m_rowCountOtherWorkers;
};

#endif // OTHERWORKERS_H
