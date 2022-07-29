import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3

Rectangle{
   id:homePlaylistRect
    property string title: ""
    signal clicked;

    clip: true
    color: Theme.backgroundColor

    Rectangle{
        anchors.fill: parent
        anchors.margins: dp(5)
        radius: dp(5)
        clip: true
        color:Theme.secondaryBackgroundColor

            AppText{
                anchors.centerIn: parent
                text: title
                color: "orange"
                font.bold: true
            }

    }

    RippleMouseArea{
        anchors.fill: parent
        onClicked: {
         homePlaylistRect.clicked()
        }
    }
}
