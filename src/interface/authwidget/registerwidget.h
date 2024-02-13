#ifndef INTERFACE_AUTHWIDGET_REGISTERWIDGET_H
#define INTERFACE_AUTHWIDGET_REGISTERWIDGET_H

#include <QWidget>
#include <QLineEdit>

class RegisterWidget : public QWidget {
    Q_OBJECT

    public:
    explicit RegisterWidget(QWidget *parent = nullptr);

    private:
    QLineEdit* username;
    QLineEdit* email;
    QLineEdit* password;
    QLineEdit* password_confirm;

    signals:
    void register_success(const QString& user_id);
    void change_parent_page();
    void clean();

};

#endif // INTERFACE_AUTHWIDGET_REGISTERWIDGET_H
