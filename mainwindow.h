#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class Drivers;
class MotorTransport;
class Routes;
class EmployedDrivers;
class VehiclesMileage;
class TravelSheets;
class OtherWorkers;
class CheckInWorkTime;
class EmployedOtherWorkers;
class TravelSheet;
class RegisterTravelSheets;
class SummaryLogByBrand;
class Help;
class AboutProgram;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showDriversForm();
    void showMotorTransportForm();
    void showRoutesForm();
    void showEmployedDriversForm();
    void showVehiclesMileageForm();
    void showTravelSheetsForm();
    void showOtherWorkersForm();
    void showCheckInWorkTimeForm();
    void showEmployedOtherWorkersForm();
    void showTravelSheetForm();
    void showRegisterTravelSheetsForm();
    void showSummaryLogByBrandForm();
    void showHelpForm();
    void showAboutProgramForm();

private:
    Ui::MainWindow *ui;
    QLabel *m_pBackground;
    Drivers *m_pDriversForm;
    MotorTransport *m_pMotorTransportForm;
    Routes *m_pRoutesForm;
    EmployedDrivers *m_pEmployedDriversForm;
    VehiclesMileage *m_pVehiclesMileageForm;
    TravelSheets *m_pTravelSheetsForm;
    OtherWorkers *m_pOtherWorkersForm;
    CheckInWorkTime *m_pCheckInWorkTimeForm;
    EmployedOtherWorkers *m_pEmployedOtherWorkersForm;
    TravelSheet *m_pTravelSheetForm;
    RegisterTravelSheets *m_pRegisterTravelSheetsForm;
    SummaryLogByBrand *m_pSummaryLogByBrandForm;
    Help *m_pHelpForm;
    AboutProgram *m_pAboutProgramForm;
};

#endif // MAINWINDOW_H
