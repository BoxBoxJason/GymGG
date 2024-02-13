#ifndef INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H
#define INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H

#include <QWidget>
#include <QLabel>

class ProfileBadgeWidget : public QWidget {
    Q_OBJECT

    public:
    explicit ProfileBadgeWidget(QWidget *parent = nullptr);

    private:
    QLabel* username_label;
    QLabel* training_counter_label;
    QLabel* user_avatar_label;

    public slots:
    void clean();
    void setUser(const QString& username, const QString& avatar_path, int training_counter);

};

#endif // INTERFACE_PROFILEWIDGET_PROFILEBADGEWIDGET_H
