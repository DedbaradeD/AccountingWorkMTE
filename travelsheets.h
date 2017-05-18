#ifndef TRAVELSHEETS_H
#define TRAVELSHEETS_H

#include <QMainWindow>

class SearchTravelSheets;

namespace Ui {
class TravelSheets;
}

class TravelSheets : public QMainWindow
{
    Q_OBJECT

public:
    explicit TravelSheets(QWidget *parent = 0);
    ~TravelSheets();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchTravelSheetsForm();

private:
    Ui::TravelSheets *ui;
    SearchTravelSheets *m_pSearchTravelSheetsForm;
};

#endif // TRAVELSHEETS_H
