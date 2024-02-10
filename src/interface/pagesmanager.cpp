#include "pagesmanager.h"

PagesManager::PagesManager(QWidget* parent){
    QStackedLayout stacked_layout(this);
    layout = &stacked_layout;

    AuthWidget auth_widget_page(this);
    auth_widget = &auth_widget_page;
    connect(auth_widget, &AuthWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(auth_widget);

    ProfileWidget profile_widget_page(this);
    profile_widget = &profile_widget_page;
    connect(profile_widget, &ProfileWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(profile_widget);

    HistoryWidget history_widget_page(this);
    history_widget = &history_widget_page;
    connect(history_widget, &HistoryWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(history_widget);

    WorkoutTemplatesWidget workout_templates_widget_page(this);
    workout_templates_widget = &workout_templates_widget_page;
    connect(workout_templates_widget, &WorkoutTemplatesWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(workout_templates_widget);

    ExercisesWidget exercises_widget_page(this);
    exercises_widget = &exercises_widget_page;
    connect(exercises_widget, &ExercisesWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(exercises_widget);

    PerformancesWidget performances_widget_page(this);
    performances_widget = &performances_widget_page;
    connect(performances_widget, &PerformancesWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(performances_widget);

    WorkoutWidget workout_widget_page(this);
    workout_widget = &workout_widget_page;
    connect(workout_widget, &WorkoutWidget::change_parent_page, this, &PagesManager::change_page);
    layout->addWidget(workout_widget);

    setLayout(layout);
}


void PagesManager::clean() {
    auth_widget->clean();
    profile_widget->clean();
}


void PagesManager::change_page(int index) {
    layout->setCurrentIndex(index);
}
