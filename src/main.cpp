#include <QApplication>
#include <QPushButton>
#include "interface/gymgg.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GymGG gymgg;
    gymgg.show();
    return QApplication::exec();
}
