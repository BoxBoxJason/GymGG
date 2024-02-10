#ifndef INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H
#define INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H

#include <QWidget>


class WorkoutTemplatesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkoutTemplatesWidget(QWidget *parent = nullptr);
    void clean();

    signals:
    void change_parent_page(int index);
};

#endif // INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H
