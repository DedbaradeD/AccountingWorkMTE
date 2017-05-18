#ifndef TRAVELSHEET_H
#define TRAVELSHEET_H

#include <QDialog>

namespace Ui {
class TravelSheet;
}

class TravelSheet : public QDialog
{
    Q_OBJECT

public:
    explicit TravelSheet(QWidget *parent = 0);
    ~TravelSheet();
    void clearDataFormTravelSheet();

private slots:
    void addTravelSheet();
    void checkBoxClicked();

private:
    Ui::TravelSheet *ui;
    bool m_downTime;
};

#endif // TRAVELSHEET_H
