#ifndef SUMMARYLOGBYBRAND_H
#define SUMMARYLOGBYBRAND_H

#include <QMainWindow>

namespace Ui {
class SummaryLogByBrand;
}

class SummaryLogByBrand : public QMainWindow
{
    Q_OBJECT

public:
    explicit SummaryLogByBrand(QWidget *parent = 0);
    ~SummaryLogByBrand();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchResult();

private:
    Ui::SummaryLogByBrand *ui;
};

#endif // SUMMARYLOGBYBRAND_H
