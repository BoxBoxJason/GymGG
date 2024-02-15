#include <QErrorMessage>
#include "pagesmanager.h"

PagesManager::PagesManager(QWidget* parent){
    QStackedLayout stacked_layout(this);
    layout = &stacked_layout;

    AuthWidget auth_widget_page(this);
    auth_widget = &auth_widget_page;
    connect(auth_widget, &AuthWidget::setUser, this, &PagesManager::setUser);
    layout->addWidget(auth_widget);

    ProfileWidget profile_widget_page(this);
    profile_widget = &profile_widget_page;
    connect(profile_widget, &ProfileWidget::changeParentPage, this, &PagesManager::change_page);
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
    history_widget->clean();
    workout_templates_widget->clean();
    exercises_widget->clean();
    performances_widget->clean();
    workout_widget->clean();
}


void PagesManager::change_page(int index) {
    layout->setCurrentIndex(index);
}


void PagesManager::setUser(QJsonObject& user,bool go_to_profile) {
    profile_widget->setUser(user);
    if (go_to_profile) {
        change_page(1);
    }
    history_widget->setUser(user);
    workout_templates_widget->setUser(user);
    exercises_widget->setUser(user);
    performances_widget->setUser(user);
    workout_widget->setUser(user);
}


void PagesManager::setWorkout(QJsonObject& workout, bool go_to_workout){
    workout_widget->setWorkout(workout);
    if (go_to_workout) {
        change_page(6);
    }
}


void PagesManager::setExercise(QJsonObject& exercise, bool go_to_exercises){
    exercises_widget->setExercise(exercise);
    if (go_to_exercises) {
        change_page(4);
    }
}


void PagesManager::setExercises(QJsonArray& exercises=QJsonArray(),bool show_exercises=false){
    exercises_widget->setExercises(exercises);
    if (show_exercises) {
        change_page(4);
    }
}


void PagesManager::showErrorMessage(const QString& message){
}


void PagesManager::showSuccessMessage(const QString& message){

}
