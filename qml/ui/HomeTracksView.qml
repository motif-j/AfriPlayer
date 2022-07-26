import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



RowLayout{
    id:root

    spacing: dp(5)
    height: dp(70)


    RoundedImage{
        property int thumbnailSize:dp(50)
        Layout.fillWidth: true
        Layout.preferredWidth: thumbnailSize
        Layout.preferredHeight: thumbnailSize
        Layout.maximumHeight: thumbnailSize
        Layout.maximumWidth: thumbnailSize
        source: "qrc:/assets/felgo-logo.png"
        fillMode: Image.Stretch
        Layout.alignment: Qt.AlignHCenter


    }

    Column{
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter

        AppText{
            text:"Song Title"
            font.bold: true
            fontSize: sp(16)
            topPadding: dp(5)

        }
        AppText{
            text:"Song Title"
            bottomPadding: dp(5)
            fontSize: sp(14)

        }
    }

    IconButton{
        Layout.alignment: Qt.AlignHCenter
        Layout.preferredWidth: dp(50)
         Layout.preferredHeight: dp(50)
        icon: IconType.play
    }

    IconButton{
        Layout.alignment: Qt.AlignHCenter
        Layout.preferredWidth: dp(30)
        icon: IconType.chevroncircleright
    }

}


