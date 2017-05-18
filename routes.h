#ifndef ROUTES_H
#define ROUTES_H

#include <QMainWindow>

class NewRoute;

namespace Ui {
class Routes;
}

class Routes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Routes(QWidget *parent = 0);
    ~Routes();

    void addTableRowRoutes(int count);
    int searchRowCountRoutes();

private slots:
    void showNewRouteForm();
    void removeRoute();

private:
    Ui::Routes *ui;
    NewRoute *m_pNewRoute;
    int m_rowCountRoutes;
};

#endif // ROUTES_H
