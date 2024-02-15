#ifndef INTERFACE_AUTHWIDGET_LOGINWIDGET_H
#define INTERFACE_AUTHWIDGET_LOGINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "../errorwidget/errorlabel.h"

class LoginWidget : public QWidget {
    Q_OBJECT

    public:
    explicit LoginWidget(QWidget *parent = nullptr);

    private:
    QLineEdit* username_or_email_input;
    QLineEdit* password_input;
    ErrorLabel* error_label;
    void login();

    public slots:
    void clean();

    signals:
    void loginSuccess(int user_id);

};

#endif // INTERFACE_AUTHWIDGET_LOGINWIDGET_H
