#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "authwidget.h"

AuthWidget::AuthWidget(QWidget* parent) : QWidget(parent) {    
    QVBoxLayout layout(this);
    QLabel page_header("Welcome to the app", this);
    page_header.setObjectName("page_header");
    layout.addWidget(&page_header, 0, Qt::AlignHCenter |Qt::AlignTop);

    // Switch login - register page buttons
    QHBoxLayout switch_buttons_layout;

    QPushButton register_switch_button_widget("Register", this);
    register_switch_button_widget.setObjectName("page_select_button");
    register_switch_button = &register_switch_button_widget;
    connect(register_switch_button, &QPushButton::clicked, this, &AuthWidget::changePage);
    switch_buttons_layout.addWidget(register_switch_button,0,Qt::AlignVCenter | Qt::AlignRight);

    QPushButton login_switch_button_widget("Login", this);
    login_switch_button_widget.setObjectName("page_select_button_selected");
    login_switch_button = &login_switch_button_widget;
    connect(login_switch_button, &QPushButton::clicked, this, &AuthWidget::changePage);
    switch_buttons_layout.addWidget(login_switch_button,0,Qt::AlignVCenter | Qt::AlignLeft);

    layout.addLayout(&switch_buttons_layout);

    // Stacked layout displaying login and register pages
    QStackedLayout stacked_layout(this);
    this->stacked_layout = &stacked_layout;
    layout.addLayout(&stacked_layout);
    setLayout(&layout);

    // Login widget
    LoginWidget login_widget_page(this);
    login_widget = &login_widget_page;
    connect(login_widget, &LoginWidget::loginSuccess, this, &AuthWidget::authentified);
    this->stacked_layout->addWidget(login_widget);

    // Register widget
    RegisterWidget register_widget_page(this);
    register_widget = &register_widget_page;
    connect(register_widget, &RegisterWidget::registerSuccess, this, &AuthWidget::authentified);
    this->stacked_layout->addWidget(register_widget);
}


void AuthWidget::changePage() {
    int current_layout_index = stacked_layout->currentIndex();
    stacked_layout->setCurrentIndex(current_layout_index ^ 1);
    if (current_layout_index == 0) {
        login_switch_button->setObjectName("page_select_button");
        register_switch_button->setObjectName("page_select_button_selected");
    } else {
        login_switch_button->setObjectName("page_select_button_selected");
        register_switch_button->setObjectName("page_select_button");
    }
}


void AuthWidget::authentified(int user_id) {
    if(user_id >= 0){
        login_widget->clean();
        register_widget->clean();
        emit setUser(QJsonObject({{"id", user_id}}),true);
    } 
}


void AuthWidget::clean() {
    login_widget->clean();
    register_widget->clean();
}
