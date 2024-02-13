#ifndef INTERFACE_HISTORYWIDGET_HISTORYWIDGET_H
#define INTERFACE_HISTORYWIDGET_HISTORYWIDGET_H

#include <QWidget>

class HistoryWidget : public QWidget {
    Q_OBJECT

    public:
    explicit HistoryWidget(QWidget* parent = nullptr);

    signals:
    void change_parent_page(int index);
    void clean();

};

#endif // INTERFACE_HISTORYWIDGET_HISTORYWIDGET_H
