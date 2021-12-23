#include <QtWidgets>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QtQml>
#include "ui_speed.h"
#include "speed.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQuickView view;

    qmlRegisterType<SpeedQML>("Speed", 1, 0, "Speed"); // 1,0 คือ version 1.0
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    return app.exec();
}
