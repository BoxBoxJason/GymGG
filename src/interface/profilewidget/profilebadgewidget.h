#ifndef INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H
#define INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H

#include <QWidget>
#include <QLabel>

class ProfileBadgeWidget : public QWidget {
    Q_OBJECT

    public:
    explicit ProfileBadgeWidget(QWidget *parent = nullptr);
    void setUser(const QString& username, const QString& avatar_path, int training_counter);
    void clean();

    private:
    QLabel* username_label;
    QLabel* training_counter_label;
    QLabel* user_avatar_label;
};

#endif // INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H
