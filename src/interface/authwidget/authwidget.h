#ifndef INTERFACE_AUTHWIDGET_AUTHWIDGET_H
#define INTERFACE_AUTHWIDGET_AUTHWIDGET_H

#include <QWidget>
#include <QStackedLayout>
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

    public slots:
    void authentified(const QString& user_id);
    void change_page();

    signals:
    void change_parent_page(int index);
    void clean();

};

#endif // INTERFACE_AUTHWIDGET_AUTHWIDGET_H
