#ifndef INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H
#define INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H

#include <QWidget>
#include <QJsonObject>

class PerformancesWidget : public QWidget {
    Q_OBJECT

    public:
    explicit PerformancesWidget(QWidget* parent = nullptr);

    signals:
    void change_parent_page(int index);

    public slots:
    void setUser(QJsonObject& user);
    void clean();

};

#endif // INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H
