#ifndef NEWOTHERWORKER_H
#define NEWOTHERWORKER_H

#include <QDialog>

class OtherWorkers;

namespace Ui {
class NewOtherWorker;
}

class NewOtherWorker : public QDialog
{
    Q_OBJECT

public:
    explicit NewOtherWorker(OtherWorkers *otherWorkers, QWidget *parent = 0);
    ~NewOtherWorker();
    void clearDataFormNewOtherWorker();

private slots:
    void addNewOtherWorker();

private:
    Ui::NewOtherWorker *ui;
    OtherWorkers *m_pOtherWorkers;
};

#endif // NEWOTHERWORKER_H
