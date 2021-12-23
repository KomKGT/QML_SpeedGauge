import QtQuick 2.6
import Speed 1.0

Rectangle {
    id: root
    width: 400
    height: 400
    color: "black"

    property int numberIndexs: 10
    property int startAngle: 225
    property int angleLength: 30
    property int maxSpeed: 45

    Speed {
        id: mySpeed
    }

    Image {
        anchors.fill: parent
        source: "speed2.png"
    }

    SpeedNeedle {
        anchors {
            top: parent.top
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
        value: mySpeed.speed
        startAngle: root.startAngle
        angleLength: root.angleLength / (root.maxSpeed / (root.numberIndexs - 1))
    }
}
