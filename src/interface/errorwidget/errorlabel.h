#ifndef INTERFACE_ERRORWIDGET_ERRORLABEL_H
#define INTERFACE_ERRORWIDGET_ERRORLABEL_H

#include <QLabel>

class ErrorLabel : public QLabel {
    Q_OBJECT

    public:
    explicit ErrorLabel(QWidget* parent=nullptr);

    public slots:
    void clean();
    void revealError();
    void hideError();

};

#endif // INTERFACE_ERRORWIDGET_ERRORLABEL_H
