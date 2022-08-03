import QtQuick 2.9
import Felgo 3.0


Rectangle{
    property color topColor: Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)
    property string title:{""}
    property int playlistId: 0
    id:root

    signal playlistClicked(plTitle:string)


    color: Theme.backgroundColor
    width:dp(320)
    height: dp(220)

    Gradient{
        id:_lgrid

        GradientStop{position: 0.0;color:topColor}
        GradientStop{position: 1.0;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
    }

    Rectangle{
        id:_parentLayout
        anchors.fill: parent
        anchors.margins: dp(5)
        radius: dp(5)
        antialiasing: true
        gradient: _lgrid

        AppText{
            text: title
            anchors.centerIn: parent
            font.pixelSize: sp(18)
            font.bold: true
            color: colorHelper.isLight(topColor)?"black":Theme.textColor

        }

    }

    RippleMouseArea{
        width: root.width
        height:root.height
        onClicked: {
           playlistClicked(title)
        }
    }





}
