#include "gymgg.h"

GymGG::GymGG(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GymGG");

    PagesManager pages_manager_widget(this);
    pages_manager = &pages_manager_widget;
    
    setCentralWidget(pages_manager);
}


void GymGG::clean() {
    pages_manager->clean();
}


void GymGG::change_page(int index) {
    pages_manager->change_page(index);
}
