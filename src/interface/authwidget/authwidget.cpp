#include <QVBoxLayout>
#include <QLabel>
#include "authwidget.h"

AuthWidget::AuthWidget(QWidget* parent) : QWidget(parent) {    
    QStackedLayout stacked_layout(this);
    this->stacked_layout = &stacked_layout;

    QVBoxLayout layout(this);
    QLabel page_header("Welcome to the app", this);
    page_header.setObjectName("page_header");
    layout.addWidget(&page_header, 0, Qt::AlignHCenter |Qt::AlignTop);

    layout.addLayout(&stacked_layout);
    setLayout(&layout);

    LoginWidget login_widget_page(this);
    login_widget = &login_widget_page;
    connect(login_widget, &LoginWidget::login_success, this, &AuthWidget::authentified);
    connect(login_widget, &LoginWidget::change_parent_page, this, &AuthWidget::change_page);
    this->stacked_layout->addWidget(login_widget);

    RegisterWidget register_widget_page(this);
    register_widget = &register_widget_page;
    connect(register_widget, &RegisterWidget::register_success, this, &AuthWidget::authentified);
    connect(register_widget, &RegisterWidget::change_parent_page, this, &AuthWidget::change_page);
    this->stacked_layout->addWidget(register_widget);
}


void AuthWidget::clean() {
    login_widget->clean();
    register_widget->clean();
}


void AuthWidget::authentified(const QString& user_id) {
    qputenv("USER_ID", user_id.toUtf8());
    emit &AuthWidget::change_parent_page(1);
}


void AuthWidget::change_page() {
    stacked_layout->setCurrentIndex(stacked_layout->currentIndex() ^ 1);
}
