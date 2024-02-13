#ifndef INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H
#define INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H

#include <QWidget>

class WorkoutWidget : public QWidget
{
    Q_OBJECT

    public:
    explicit WorkoutWidget(QWidget *parent = nullptr);

    signals:
    void change_parent_page(int index);
    void clean();

};

#endif // INTERFACE_WORKOUTWIDGET_WORKOUTWIDGET_H
