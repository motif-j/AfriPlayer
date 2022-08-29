import QtQuick 2.0
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3
import Felgo 3.0

Rectangle {
    width: parent.width
    height: dp(80)
    property string title: ""
    property int  plId: 0
    color: "transparent"


    RowLayout{
        width: parent.width
        height: parent.height

        Rectangle{
            id:root

            width: dp(80)
            height: parent.height
            Layout.maximumWidth: dp(80)

            radius: dp(3)
            antialiasing: true
            clip: true

            LinearGradient{
                anchors.fill: parent
                start: Qt.point(root.width-dp(2),0)
                end:Qt.point(0,root.height-dp(2))
                gradient: Gradient{
                    id:_lgrid

                    GradientStop{position: 0.0;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
                    // GradientStop{position: 0.25;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
                    GradientStop{position: 0.50;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
                    GradientStop{position: 0.75;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}

                    GradientStop{position: 1.0;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}

                }
            }
        }


        AppText{
            text: title
            fontSize: 14
            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            Layout.leftMargin: dp(10)
            Layout.fillWidth: true

        }


    }

}
