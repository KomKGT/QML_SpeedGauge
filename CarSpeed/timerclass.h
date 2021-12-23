#ifndef TIMERCLASS_H
#define TIMERCLASS_H

#include<QTimer>
#include <QObject>

class timerclass : public QObject
{
    Q_OBJECT
public:
    timerclass();
private slots:
    void timerSlot();

signals:
    void timerCustomSignal(int);

private:
    QTimer *timer;
    int timeCount;
};

#endif // TIMERCLASS_H
