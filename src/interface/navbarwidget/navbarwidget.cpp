#include "navbarwidget.h"

NavBarWidget::NavBarWidget(QWidget* parent)
    : QToolBar(parent)
{
    profile_action = new QAction("Profile", this);
    profile_action->setIcon(QIcon(":/icons/profile.png"));
    addAction(profile_action);
    connect(profile_action, &QAction::triggered, [this](){ emit change_page(1); });

    history_action = new QAction("History", this);
    history_action->setIcon(QIcon(":/icons/time.png"));
    addAction(history_action);
    connect(history_action, &QAction::triggered, [this](){ emit change_page(2); });

    workout_templates_action = new QAction("Workout Templates", this);
    workout_templates_action->setIcon(QIcon(":/icons/add.png"));
    addAction(workout_templates_action);
    connect(workout_templates_action, &QAction::triggered, [this](){ emit change_page(3); });

    exercises_action = new QAction("Exercises", this);
    exercises_action->setIcon(QIcon(":/icons/dumbbell.png"));
    addAction(exercises_action);
    connect(exercises_action, &QAction::triggered, [this](){ emit change_page(4); });

    performances_action = new QAction("Performances", this);
    performances_action->setIcon(QIcon(":/icons/performance.png"));
    addAction(performances_action);
    connect(performances_action, &QAction::triggered, [this](){ emit change_page(5); });
}
