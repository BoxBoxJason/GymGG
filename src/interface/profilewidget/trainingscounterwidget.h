#ifndef INTERFACE_PROFILEWIDGET_TRAININGSCOUNTERWIDGET_H
#define INTERFACE_PROFILEWIDGET_TRAININGSCOUNTERWIDGET_H

#include <QWidget>
#include <QJsonObject>

class TrainingsCounterWidget : public QWidget {
    Q_OBJECT

    public:
    explicit TrainingsCounterWidget(QWidget *parent = nullptr);
    void setTrainingsCounter(const QJsonObject& trainings_counter);
    void clean();

    private:

};

#endif // INTERFACE_PROFILEWIDGET_TRAININGSCOUNTERWIDGET_H
