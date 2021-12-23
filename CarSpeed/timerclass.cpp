#include "timerclass.h"
#include <QDebug>
timerclass::timerclass()
{
    timer = new QTimer;
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));

    timeCount = 0;
}

void timerclass::timerSlot()
{
    qDebug() <<"timeCount" << timeCount;
    emit timerCustomSignal(timeCount);
    timeCount++;
}
