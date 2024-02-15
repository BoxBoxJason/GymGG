#ifndef INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H
#define INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H

#include <QWidget>
#include <QJsonObject>

class WorkoutTemplatesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkoutTemplatesWidget(QWidget *parent = nullptr);

    signals:
    void change_parent_page(int index);

    public slots:
    void setUser(QJsonObject& user);
    void clean();

};

#endif // INTERFACE_WORKOUTTEMPLATESWIDGET_WORKOUTTEMPLATESWIDGET_H
