#ifndef INTERFACE_GYMGG_H
#define INTERFACE_GYMGG_H

#include <QMainWindow>
#include "pagesmanager.h"

class GymGG : public QMainWindow {
    Q_OBJECT

    public:
    explicit GymGG(QWidget *parent = nullptr);

    private:
    PagesManager* pages_manager;

    public slots:
    void change_page(int index);
    void clean();

};

#endif // INTERFACE_GYMGG_H
