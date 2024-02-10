#ifndef INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H
#define INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H

#include <QWidget>

class PerformancesWidget : public QWidget {
    Q_OBJECT

    public:
    explicit PerformancesWidget(QWidget* parent = nullptr);
    void clean();

    signals:
    void change_parent_page(int index);
};

#endif // INTERFACE_PERFORMANCESWIDGET_PERFORMANCESWIDGET_H
