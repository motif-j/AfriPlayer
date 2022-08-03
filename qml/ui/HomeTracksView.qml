import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



Rectangle{
    color:"#00000000"
    id:root


    RowLayout{

        width: root.width
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
            Layout.leftMargin: dp(5)


        }

        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            AppText{
                text:"Song Title"
                font.bold: true
                font.pixelSize:  sp(14)
                topPadding: dp(5)

            }
            AppText{
                text:"artist"
                bottomPadding: dp(5)
                font.pixelSize:  sp(12)
                color: Theme.secondaryTextColor

            }
        }

        IconButton{
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: dp(40)
            Layout.preferredHeight: dp(40)
            icon: IconType.play


        }


    }
}


