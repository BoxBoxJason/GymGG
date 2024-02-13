#ifndef INTERFACE_AUTHWIDGET_LOGINWIDGET_H
#define INTERFACE_AUTHWIDGET_LOGINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QString>

class LoginWidget : public QWidget {
    Q_OBJECT

    public:
    explicit LoginWidget(QWidget *parent = nullptr);

    private:

    
    QLineEdit* username_or_email;
    QLineEdit* password;

    signals:
    void login_success(const QString& user_id);
    void change_parent_page();
    void clean();

};

#endif // INTERFACE_AUTHWIDGET_LOGINWIDGET_H
