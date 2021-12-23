#include "speed.h"
#include "ui_speed.h"
#include "timerclass.h"

Speed::Speed():QWidget(0),ui(new Ui::Speed)  //Constructor ของ speed.h
{
    ui->setupUi(this);

    timerObj = new timerclass();
    connect(timerObj,SIGNAL(timerCustomSignal(int)),this,SIGNAL(speedChanged(int)));

    connect(ui->speedSlider,SIGNAL(valueChanged(int)),this,SIGNAL(speedChanged(int)));
}
void Speed::timerCustomSlot(int value)
{
    ui->label->setText("<center>"+QString::number(value)+"</center>");
}

SpeedQML::SpeedQML(QObject *parent) : QObject(parent) //Constructor ของ QML
{
    m_speed.setVisible(true);
    m_speedData = 0;
    connect(&m_speed, SIGNAL(speedChanged(int)), this, SLOT(updateSpeed(int)));
}

int SpeedQML::speed() const {
    return m_speedData;
}

void SpeedQML::updateSpeed(int value){
    m_speedData = value;
    emit speedChanged();
}
