#include <QPushButton>
#include <QVBoxLayout>
#include "registerwidget.h"
#include "../../database/controllers/user.h"
#include "../../database/models/user.h"
#include "../errorwidget/errorlabel.h"
#include "../../utils/utils.h"


RegisterWidget::RegisterWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout layout(this);

    QLabel username_label("Username", this);
    layout.addWidget(&username_label,Qt::AlignHCenter);

    QLineEdit username_input_widget(this);
    username_input = &username_input_widget;
    username_input->setPlaceholderText("Username");
    layout.addWidget(username_input,Qt::AlignHCenter);

    QLabel email_label("Email", this);
    layout.addWidget(&email_label,Qt::AlignHCenter);

    QLineEdit email_input_widget(this);
    email_input = &email_input_widget;
    email_input->setPlaceholderText("Email");
    layout.addWidget(email_input,Qt::AlignHCenter);

    QLabel password_label("Password", this);
    layout.addWidget(&password_label,Qt::AlignHCenter);

    QLineEdit password_input_widget(this);
    password_input = &password_input_widget;
    password_input->setPlaceholderText("Password");
    layout.addWidget(password_input,Qt::AlignHCenter);

    QLabel password_confirm_label("Confirm Password", this);
    layout.addWidget(&password_confirm_label,Qt::AlignHCenter);

    QLineEdit password_confirm_input_widget(this);
    password_confirm_input = &password_confirm_input_widget;
    password_confirm_input->setPlaceholderText("Confirm Password");
    layout.addWidget(password_confirm_input,Qt::AlignHCenter);

    QPushButton register_button(this);
    register_button.setText("Register");
    connect(&register_button, &QPushButton::clicked, this, &RegisterWidget::registerUser);
    layout.addWidget(&register_button,Qt::AlignHCenter);

    setLayout(&layout);
}


void RegisterWidget::registerUser() {
    QString password = password_input->text().trimmed();
    QString password_confirm = password_confirm_input->text().trimmed();
    QString username = username_input->text().trimmed();
    QString email = email_input->text().trimmed();

    // Validate inputs before sending to the database
    bool input_error = true;
    if (password != password_confirm) {
        error_label->setText("Passwords do not match");
    } else if (username.isEmpty() || email.isEmpty() || password.isEmpty()) {
        error_label->setText("All fields are required");
    } else if (!usernameValid(username)) {
        error_label->setText("Invalid username");
    } else if (!usernameExists(username)) {
        error_label->setText("Username already in use");
    } else if (!emailValid(email)) {
        error_label->setText("Invalid email");
    } else if (!userEmailExists(email)) {
        error_label->setText("Email already in use");
    } else if (!passwordValid(password)) {
        error_label->setText("Invalid password");
    } else {
        int user_id = createUser(username, email, password);
        emit registerSuccess(user_id);
        input_error = false;
    }

    if (input_error) {
        error_label->show();
    }
}


void RegisterWidget::clean() {
    username_input->clear();
    email_input->clear();
    password_input->clear();
    password_confirm_input->clear();
    error_label->clean();
}
