import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3

Rectangle{

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
                text: "Playlist 1"
                color: "orange"
                font.bold: true
            }




    }
}
