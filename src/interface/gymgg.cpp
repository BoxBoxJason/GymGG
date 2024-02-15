#include "gymgg.h"

GymGG::GymGG(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GymGG");

    PagesManager pages_manager_widget(this);
    pages_manager = &pages_manager_widget;
    setCentralWidget(pages_manager);

    NavBarWidget navbar_widget(this);
    navbar = &navbar_widget;
    addToolBar(navbar);
    
    connect(navbar, &NavBarWidget::change_page, pages_manager, &PagesManager::change_page);
}
