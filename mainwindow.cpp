#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "drivers.h"
#include "motortransport.h"
#include "routes.h"
#include "employeddrivers.h"
#include "vehiclesmileage.h"
#include "travelsheets.h"
#include "otherworkers.h"
#include "checkinworktime.h"
#include "employedotherworkers.h"
#include "travelsheet.h"
#include "registertravelsheets.h"
#include "summarylogbybrand.h"
#include "help.h"
#include "aboutprogram.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pBackground = new QLabel();
    m_pBackground->setPixmap(QPixmap(":/images/Background.jpg"));
    m_pBackground->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_pBackground->setScaledContents(true);
    setCentralWidget(m_pBackground);
    m_pDriversForm = new Drivers();
    m_pMotorTransportForm = new MotorTransport();
    m_pRoutesForm = new Routes();
    m_pEmployedDriversForm = new EmployedDrivers();
    m_pVehiclesMileageForm = new VehiclesMileage();
    m_pTravelSheetsForm = new TravelSheets();
    m_pOtherWorkersForm = new OtherWorkers();
    m_pCheckInWorkTimeForm = new CheckInWorkTime();
    m_pEmployedOtherWorkersForm = new EmployedOtherWorkers();
    m_pTravelSheetForm = new TravelSheet();
    m_pRegisterTravelSheetsForm = new RegisterTravelSheets();
    m_pSummaryLogByBrandForm = new SummaryLogByBrand();
    m_pHelpForm = new Help();
    m_pAboutProgramForm = new AboutProgram();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pBackground;
    delete m_pDriversForm;
    delete m_pMotorTransportForm;
    delete m_pRoutesForm;
    delete m_pEmployedDriversForm;
    delete m_pVehiclesMileageForm;
    delete m_pTravelSheetsForm;
    delete m_pOtherWorkersForm;
    delete m_pCheckInWorkTimeForm;
    delete m_pEmployedOtherWorkersForm;
    delete m_pTravelSheetForm;
    delete m_pRegisterTravelSheetsForm;
    delete m_pSummaryLogByBrandForm;
    delete m_pHelpForm;
    delete m_pAboutProgramForm;
}

void MainWindow::showDriversForm()
{
    m_pDriversForm->show();
}

void MainWindow::showMotorTransportForm()
{
    m_pMotorTransportForm->show();
}

void MainWindow::showRoutesForm()
{
    m_pRoutesForm->show();
}

void MainWindow::showEmployedDriversForm()
{
    m_pEmployedDriversForm->show();
}

void MainWindow::showVehiclesMileageForm()
{
    m_pVehiclesMileageForm->show();
}

void MainWindow::showTravelSheetsForm()
{
    m_pTravelSheetsForm->show();
}

void MainWindow::showOtherWorkersForm()
{
    m_pOtherWorkersForm->show();
}

void MainWindow::showCheckInWorkTimeForm()
{
    m_pCheckInWorkTimeForm->show();
}

void MainWindow::showEmployedOtherWorkersForm()
{
    m_pEmployedOtherWorkersForm->show();
}

void MainWindow::showTravelSheetForm()
{
    m_pTravelSheetForm->show();
}

void MainWindow::showRegisterTravelSheetsForm()
{
    m_pRegisterTravelSheetsForm->show();
}

void MainWindow::showSummaryLogByBrandForm()
{
    m_pSummaryLogByBrandForm->show();
}

void MainWindow::showHelpForm()
{
    m_pHelpForm->show();
}

void MainWindow::showAboutProgramForm()
{
    m_pAboutProgramForm->show();
}
