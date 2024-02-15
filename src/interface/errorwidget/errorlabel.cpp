#include "errorlabel.h"

ErrorLabel::ErrorLabel(QWidget* parent) : QLabel(parent) {
    setWordWrap(true);
    setAlignment(Qt::AlignCenter);
    setVisible(false);
}


void ErrorLabel::clean() {
    setText("");
    setVisible(false);
}


void ErrorLabel::revealError() {
    setVisible(true);
}


void ErrorLabel::hideError() {
    setVisible(false);
}
