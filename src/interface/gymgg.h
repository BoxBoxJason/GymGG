#ifndef INTERFACE_GYMGG_H
#define INTERFACE_GYMGG_H

#include <QMainWindow>
#include "pagesmanager.h"
#include "navbarwidget/navbarwidget.h"

class GymGG : public QMainWindow {
    Q_OBJECT

    public:
    explicit GymGG(QWidget *parent = nullptr);

    private:
    PagesManager* pages_manager;
    NavBarWidget* navbar;

};

#endif // INTERFACE_GYMGG_H
