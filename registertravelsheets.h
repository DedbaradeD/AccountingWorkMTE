#ifndef REGISTERTRAVELSHEETS_H
#define REGISTERTRAVELSHEETS_H

#include <QMainWindow>

namespace Ui {
class RegisterTravelSheets;
}

class RegisterTravelSheets : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterTravelSheets(QWidget *parent = 0);
    ~RegisterTravelSheets();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchResult();

private:
    Ui::RegisterTravelSheets *ui;
};

#endif // REGISTERTRAVELSHEETS_H
