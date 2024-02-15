#ifndef INTERFACE_AUTHWIDGET_AUTHWIDGET_H
#define INTERFACE_AUTHWIDGET_AUTHWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QJsonObject>
#include <QPushButton>
#include "loginwidget.h"
#include "registerwidget.h"

class AuthWidget : public QWidget {
    Q_OBJECT

    public:
    explicit AuthWidget(QWidget *parent = nullptr);

    private:
    QStackedLayout* stacked_layout;
    LoginWidget* login_widget;
    RegisterWidget* register_widget;
    QPushButton* register_switch_button;
    QPushButton* login_switch_button;

    public slots:
    void changePage();
    void authentified(int user_id);
    void clean();

    signals:
    void setUser(QJsonObject& user,bool go_to_profile);

};

#endif // INTERFACE_AUTHWIDGET_AUTHWIDGET_H
