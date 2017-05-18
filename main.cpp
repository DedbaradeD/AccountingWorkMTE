#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

bool createConnectionMySQL();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnectionMySQL())
        return 1;
    MainWindow w;
    w.show();
    return a.exec();
}

bool createConnectionMySQL()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("AccountingWorkMTE");
    db.setUserName("root");
    db.setPassword("admin");
    if (!db.open()) {
        qDebug() << "Can not open data base:" << db.lastError();
        return false;
    }
    return true;
}
