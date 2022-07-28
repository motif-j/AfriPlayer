import QtQuick 2.9
import Felgo 3.0


Rectangle{
    color: Theme.backgroundColor
    width:dp(320)
    height: dp(220)


    Rectangle{
        anchors.fill: parent
        anchors.margins: dp(5)
        radius: dp(5)
        gradient: Gradient{
            GradientStop{position: 0.0;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
            GradientStop{position: 1.0;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
        }


    }

}
