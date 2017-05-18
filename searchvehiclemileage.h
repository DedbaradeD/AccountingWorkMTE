#ifndef SEARCHVEHICLEMILEAGE_H
#define SEARCHVEHICLEMILEAGE_H

#include <QDialog>

class VehiclesMileage;

namespace Ui {
class SearchVehicleMileage;
}

class SearchVehicleMileage : public QDialog
{
    Q_OBJECT

public:
    explicit SearchVehicleMileage(VehiclesMileage *vehiclesMileage, QWidget *parent = 0);
    ~SearchVehicleMileage();

private slots:
    void checkBoxClicked();
    void showSearchResult();

private:
    Ui::SearchVehicleMileage *ui;
    VehiclesMileage *m_pVehiclesMileage;
    bool m_period;
};

#endif // SEARCHVEHICLEMILEAGE_H
