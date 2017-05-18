#ifndef SEARCHEMPLOYEDDRIVERS_H
#define SEARCHEMPLOYEDDRIVERS_H

#include <QDialog>

class EmployedDrivers;

namespace Ui {
class SearchEmployedDrivers;
}

class SearchEmployedDrivers : public QDialog
{
    Q_OBJECT

public:
    explicit SearchEmployedDrivers(EmployedDrivers *employedDrivers, QWidget *parent = 0);
    ~SearchEmployedDrivers();

private slots:
    void checkBoxClicked();
    void showSearchResult();

private:
    Ui::SearchEmployedDrivers *ui;
    EmployedDrivers *m_pEmployedDrivers;
    bool m_period;
};

#endif // SEARCHEMPLOYEDDRIVERS_H
