import QtQuick 2.9
import QtQuick.Layouts 1.3
import Felgo 3.0



RowLayout{


    id:root

    spacing: dp(5)


    Row{
        Layout.preferredHeight: dp(65)
        RoundedImage{
            property int thumbnailSize:dp(60)
            height: thumbnailSize
            width: thumbnailSize
            source: "qrc:/assets/qt.png"
            fillMode: Image.Stretch
            Layout.alignment: Qt.AlignHCenter


        }
        Rectangle{
            width: dp(5)
        }

        Column{
           width: dp(100)
           height: dp(65)
           spacing: dp(5)
           leftPadding: dp(5)


            AppText{
                text:"Song Title"
                font.bold: true
                fontSize: sp(16)
                topPadding: dp(5)

            }
            AppText{
                text:"artist"
                bottomPadding: dp(5)
                fontSize: sp(14)
                color: Theme.secondaryTextColor

            }
        }
    }




    AppText{
        text:"Album"

        fontSize: sp(16)

        Layout.alignment: Qt.AlignHCenter
        Layout.maximumWidth: dp(60)
        Layout.preferredWidth: dp(50)

    }


    AppText{
        text:"13:00:00"

        fontSize: sp(16)

        Layout.alignment: Qt.AlignHCenter
        Layout.maximumWidth: dp(60)
        Layout.preferredWidth: dp(50)

    }

    IconButton{
        Layout.alignment: Qt.AlignHCenter
        Layout.preferredWidth: dp(40)
        Layout.preferredHeight: dp(40)
        icon: IconType.play


    }



}


