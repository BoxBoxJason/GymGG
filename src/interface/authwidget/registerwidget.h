#ifndef INTERFACE_AUTHWIDGET_REGISTERWIDGET_H
#define INTERFACE_AUTHWIDGET_REGISTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "../errorwidget/errorlabel.h"

class RegisterWidget : public QWidget {
    Q_OBJECT

    public:
    explicit RegisterWidget(QWidget *parent = nullptr);

    private:
    QLineEdit* username_input;
    QLineEdit* email_input;
    QLineEdit* password_input;
    QLineEdit* password_confirm_input;
    ErrorLabel* error_label;
    void registerUser();

    public slots:
    void clean();

    signals:
    void registerSuccess(int user_id);

};

#endif // INTERFACE_AUTHWIDGET_REGISTERWIDGET_H
