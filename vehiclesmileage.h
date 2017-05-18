#ifndef VEHICLESMILEAGE_H
#define VEHICLESMILEAGE_H

#include <QMainWindow>

class SearchVehicleMileage;

namespace Ui {
class VehiclesMileage;
}

class VehiclesMileage : public QMainWindow
{
    Q_OBJECT

public:
    explicit VehiclesMileage(QWidget *parent = 0);
    ~VehiclesMileage();

    void addTableWidgetRows(int counter, QString *arrayData);

private slots:
    void showSearchVehicleMileageForm();

private:
    Ui::VehiclesMileage *ui;
    SearchVehicleMileage *m_pSearchVehicleMileageForm;
};

#endif // VEHICLESMILEAGE_H
