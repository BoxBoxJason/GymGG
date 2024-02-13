#ifndef INTERFACE_PAGESMANAGER_H
#define INTERFACE_PAGESMANAGER_H

#include <QWidget>
#include <QStackedLayout>
#include "authwidget/authwidget.h"
#include "profilewidget/profilewidget.h"
#include "historywidget/historywidget.h"
#include "workouttemplateswidget/workouttemplateswidget.h"
#include "exerciseswidget/exerciseswidget.h"
#include "performanceswidget/performanceswidget.h"
#include "workoutwidget/workoutwidget.h"

class PagesManager : public QWidget {
    Q_OBJECT

    public:
    explicit PagesManager(QWidget* parent=nullptr);

    private:
    QStackedLayout* layout;
    AuthWidget* auth_widget;
    ProfileWidget* profile_widget;
    HistoryWidget* history_widget;
    WorkoutTemplatesWidget* workout_templates_widget;
    ExercisesWidget* exercises_widget;
    PerformancesWidget* performances_widget;
    WorkoutWidget* workout_widget;

    public slots:
    void change_page(int index);
    void clean();

};

#endif // INTERFACE_PAGESMANAGER_H
