#ifndef INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H
#define INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>

class ExercisesWidget : public QWidget {
    Q_OBJECT

    public:
    explicit ExercisesWidget(QWidget* parent = nullptr);

    signals:
    void change_parent_page(int index);
    void clean();

    public slots:
    void setUser(QJsonObject& user);
    void setExercise(QJsonObject& exercise);
    void setExercises(QJsonArray& exercises);
};

#endif // INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H