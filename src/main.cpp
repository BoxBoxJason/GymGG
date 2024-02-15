#include <QApplication>
#include <QPushButton>
#include "interface/gymgg.h"


void customErrorHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    if (type == QtFatalMsg) {
        // This is a fatal message (uncaught exception)
        // Emit a signal or perform any special handling here
        qDebug() << "Uncaught exception occurred:";
        qDebug() << msg;

        // Exit the application or take appropriate action
        QCoreApplication::exit(1);
    }
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qInstallMessageHandler(customErrorHandler);
    GymGG gymgg;
    gymgg.show();
    return QApplication::exec();
}
