#ifndef NEWROUTE_H
#define NEWROUTE_H

#include <QDialog>

class Routes;

namespace Ui {
class NewRoute;
}

class NewRoute : public QDialog
{
    Q_OBJECT

public:
    explicit NewRoute(Routes *routes, QWidget *parent = 0);
    ~NewRoute();
    void clearDataFormNewRoute();

private slots:
    void addNewRoute();

private:
    Ui::NewRoute *ui;
    Routes *m_pRoutes;
};

#endif // NEWROUTE_H
