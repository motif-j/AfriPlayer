import QtQuick 2.9
import QtQuick.Layouts 1.3
import Felgo 3.0

import com.afriktek.qplayer 1.0



RowLayout{

    property string trackName: ""
    property string artistName: ""
    property string albumName: ""
    property string duration: "13 : 12"

    id:root

    spacing: dp(5)


    Row{
        Layout.preferredHeight: dp(65)
        Layout.margins: dp(5)
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
                text:trackName
                font.bold: true
                fontSize: sp(16)
                topPadding: dp(5)

            }
            AppText{
                text:artistName
                bottomPadding: dp(5)
                fontSize: sp(14)
                color: Theme.secondaryTextColor

            }
        }
    }




    AppText{
        text:albumName

        fontSize: sp(16)

        Layout.alignment: Qt.AlignHCenter
        Layout.maximumWidth: dp(60)
        Layout.preferredWidth: dp(50)

    }


    AppText{
        text:duration

        fontSize: sp(18)
        font.family: Constants.lcdFont.name
        font.letterSpacing: dp(2)


        Layout.alignment: Qt.AlignHCenter
        Layout.maximumWidth: dp(100)
        Layout.preferredWidth: dp(80)

    }

    IconButton{
        Layout.alignment: Qt.AlignHCenter
        Layout.preferredWidth: dp(40)
        Layout.preferredHeight: dp(40)
        icon: IconType.play


    }



}


