#ifndef INTERFACE_GYMGG_H
#define INTERFACE_GYMGG_H

#include <QMainWindow>
#include "pagesmanager.h"

class GymGG : public QMainWindow {
    Q_OBJECT

    public:
    explicit GymGG(QWidget *parent = nullptr);
    void clean();

    private:
    PagesManager* pages_manager;

    public slots:
    void change_page(int index);
};

#endif // INTERFACE_GYMGG_H
