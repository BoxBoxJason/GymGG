#ifndef INTERFACE_PROFILEWIDGET_PROFILEWIDGET_H
#define INTERFACE_PROFILEWIDGET_PROFILEWIDGET_H

#include <QStackedLayout>
#include <QWidget>
#include <QLabel>
#include "profilebadgewidget.h"
#include "trainingscounterwidget.h"

class ProfileWidget : public QWidget {
    Q_OBJECT

    public:
    explicit ProfileWidget(QWidget *parent = nullptr);
    void clean();
    void set_player(const QString& player_id);

    private:
    QStackedLayout* layout;
    ProfileBadgeWidget* user_badge_widget;
    TrainingsCounterWidget* trainings_counter_widget;

    public slots:
    void change_page(int index);

    signals:
    void change_parent_page(int index);
};

#endif // INTERFACE_PROFILEWIDGET_PROFILEWIDGET_H
