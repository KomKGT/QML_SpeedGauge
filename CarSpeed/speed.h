#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <timerclass.h>

namespace Ui {
class Speed;
}
//ของ slider speed
class Speed : public QWidget
{
    Q_OBJECT

public:
    Speed();

signals:
    void speedChanged(int);

private slots:
    void timerCustomSlot(int);

private:
    Ui::Speed *ui;
    int m_value;
    timerclass *timerObj;
};
//ของ QML
class SpeedQML : public QObject {
    Q_OBJECT

    Q_PROPERTY(int speed READ speed NOTIFY speedChanged)
public:
    SpeedQML(QObject *parent = 0);
    int speed() const;

public slots:
    void updateSpeed(int);



signals:
    void speedChanged();

private:
    int m_speedData;
    Speed m_speed;


};

#endif // SPEED_H
