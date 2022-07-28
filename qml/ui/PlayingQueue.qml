import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



RowLayout{
    id:root

    spacing: dp(5)
    height: dp(50)


    Column{
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter

        AppText{
            text:"Song Title"
            font.bold: true
            fontSize: sp(14)
            topPadding: dp(5)
            Layout.alignment: Qt.AlignHCenter

        }
        AppText{
            text:"Song Title"
            bottomPadding: dp(5)
            fontSize: sp(12)
            color: Theme.secondaryTextColor
            Layout.alignment: Qt.AlignHCenter

        }
    }

    IconButton{
        Layout.alignment: Qt.AlignHCenter
        icon: IconType.play


    }



}


