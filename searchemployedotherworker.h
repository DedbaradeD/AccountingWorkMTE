#ifndef SEARCHEMPLOYEDOTHERWORKER_H
#define SEARCHEMPLOYEDOTHERWORKER_H

#include <QDialog>

class EmployedOtherWorkers;

namespace Ui {
class SearchEmployedOtherWorker;
}

class SearchEmployedOtherWorker : public QDialog
{
    Q_OBJECT

public:
    explicit SearchEmployedOtherWorker(EmployedOtherWorkers *employedOtherWorkers, QWidget *parent = 0);
    ~SearchEmployedOtherWorker();

private slots:
    void checkBoxClicked();
    void showSearchResult();

private:
    Ui::SearchEmployedOtherWorker *ui;
    bool m_period;
    EmployedOtherWorkers *m_pEmployedOtherWorkers;
};

#endif // SEARCHEMPLOYEDOTHERWORKER_H
