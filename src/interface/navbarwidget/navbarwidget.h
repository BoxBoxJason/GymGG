#ifndef INTERFACE_NAVBARWIDGET_NAVBARWIDGET_H
#define INTERFACE_NAVBARWIDGET_NAVBARWIDGET_H

#include <QToolBar>

class NavBarWidget : public QToolBar {
    Q_OBJECT

    public:
    explicit NavBarWidget(QWidget* parent=nullptr);

    private:
    QAction* profile_action;
    QAction* history_action;
    QAction* workout_templates_action;
    QAction* exercises_action;
    QAction* performances_action;

    signals:
    void change_page(int index);

};

#endif // INTERFACE_NAVBARWIDGET_NAVBARWIDGET_H
