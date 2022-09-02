import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3

Rectangle{
    id:homePlaylistRect
    property string title: ""
    property int playlistId : 0
    signal playlistClicked;

    clip: true
    color: Theme.backgroundColor

    Rectangle{
        anchors.fill: homePlaylistRect
        anchors.margins: dp(5)
        radius: dp(5)
        clip: true
        color:Theme.secondaryBackgroundColor

        AppText{


            anchors.centerIn: parent
            anchors.margins: dp(5)
            width: homePlaylistRect.width
            text: title
            color: "orange"
            horizontalAlignment: Text.Center
            font.bold: true
            font.pixelSize:  sp(14)

        }

    }

    RippleMouseArea{
        width: homePlaylistRect.width
        height: homePlaylistRect.height
        onClicked: {
            homePlaylistRect.playlistClicked()
        }
    }
}
