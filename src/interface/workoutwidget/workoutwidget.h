#ifndef INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H
#define INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H

#include <QWidget>
#include <QJsonObject>

class WorkoutWidget : public QWidget
{
    Q_OBJECT

    public:
    explicit WorkoutWidget(QWidget *parent = nullptr);

    signals:
    void change_parent_page(int index);

    public slots:
    void setWorkout(QJsonObject& workout);
    void clean();
    void setUser(QJsonObject& user);

};

#endif // INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H
