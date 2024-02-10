#ifndef INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H
#define INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H

#include <QWidget>

class ExercisesWidget : public QWidget {
    Q_OBJECT

    public:
    explicit ExercisesWidget(QWidget* parent = nullptr);
    void clean();

    signals:
    void change_parent_page(int index);
};

#endif // INTERFACE_EXERCISESWIDGET_EXERCISESWIDGET_H