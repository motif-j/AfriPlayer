import QtQuick 2.0
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3
import Felgo 3.0

Rectangle {
    property string  themeColors: ""

    width: parent.width
    height: dp(80)
    property string title: ""
    property int  plId: 0
    color: "transparent"



    RowLayout{
        width: parent.width
        height: parent.height

       RoundedImage{
            id:root

            width: dp(80)
            height: parent.height
            Layout.maximumWidth: dp(80)

            radius: dp(3)
            source: "image://gthumbnail/"+themeColors
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
