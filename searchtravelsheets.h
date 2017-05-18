#ifndef SEARCHTRAVELSHEETS_H
#define SEARCHTRAVELSHEETS_H

#include <QDialog>

class TravelSheets;

namespace Ui {
class SearchTravelSheets;
}

class SearchTravelSheets : public QDialog
{
    Q_OBJECT

public:
    explicit SearchTravelSheets(TravelSheets *travelSheets, QWidget *parent = 0);
    ~SearchTravelSheets();

private slots:
    void checkBoxClicked();
    void showSearchResult();

private:
    Ui::SearchTravelSheets *ui;
    TravelSheets *m_pTravelSheets;
    bool m_period;
};

#endif // SEARCHTRAVELSHEETS_H
