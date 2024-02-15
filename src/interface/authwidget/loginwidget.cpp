#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "loginwidget.h"
#include "../../database/controllers/user.h"

LoginWidget::LoginWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout layout(this);

    QLabel username_label("Username or Email", this);
    layout.addWidget(&username_label,Qt::AlignHCenter);

    QLineEdit username_or_email_input_widget(this);
    username_or_email_input = &username_or_email_input_widget;
    username_or_email_input->setPlaceholderText("Username or Email");
    layout.addWidget(username_or_email_input,Qt::AlignHCenter);

    QLabel password_label("Password", this);
    layout.addWidget(&password_label,Qt::AlignHCenter);

    QLineEdit password_input_widget(this);
    password_input = &password_input_widget;
    password_input->setPlaceholderText("Password");
    layout.addWidget(password_input,Qt::AlignHCenter);

    QPushButton login_button(this);
    login_button.setText("Login");
    connect(&login_button, &QPushButton::clicked, this, &LoginWidget::login);
    layout.addWidget(&login_button,Qt::AlignHCenter);

    setLayout(&layout);
}


void LoginWidget::login() {
    QString username_or_email = username_or_email_input->text().trimmed();
    QString password = password_input->text().trimmed();
    int user_id = getUserIdFromUsernameOrEmail(username_or_email);
    if(user_id >= 0 && checkUserPasswordMatches(user_id, password)) {
        emit loginSuccess(user_id);
    } else {
        error_label->setText("Invalid username or password");
        error_label->revealError();
    }
}


void LoginWidget::clean() {
    username_or_email_input->clear();
    password_input->clear();
    error_label->clean();
}
