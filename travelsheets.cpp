#include "travelsheets.h"
#include "ui_travelsheets.h"
#include "searchtravelsheets.h"

TravelSheets::TravelSheets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TravelSheets)
{
    ui->setupUi(this);
    m_pSearchTravelSheetsForm = new SearchTravelSheets(this);
}

TravelSheets::~TravelSheets()
{
    delete ui;
    delete m_pSearchTravelSheetsForm;
}

void TravelSheets::showSearchTravelSheetsForm()
{
    m_pSearchTravelSheetsForm->show();
}

void TravelSheets::addTableWidgetRows(int counter, QString *arrayData)
{
    ui->tableWidget->setRowCount(counter + 1);
    for (int i = counter; i == counter; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem();
            pItem->setText(QString(arrayData[j]).arg(i).arg(j));
            ui->tableWidget->setItem(i, j, pItem);
        }
    }
}
