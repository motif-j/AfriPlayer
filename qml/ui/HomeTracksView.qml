import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



Rectangle{
    color:"#00000000"
    id:root
    property string trackName: ""
    property string artistName: ""
    property string albumName: ""
    property int  trackId: 0
    property bool isFavorite: false

    property color thumbnailColor: Qt.rgba(Math.random(255),Math.random(255),Math.random(255),1)
    property color thumbnailColor2: Qt.rgba(Math.random(255),Math.random(255),Math.random(255),1)
    property color thumbnailColor3: Qt.rgba(Math.random(155),Math.random(200),Math.random(55),1)


    RowLayout{

        width: root.width
        spacing: dp(5)
        height: dp(70)


       Rectangle{
            property int thumbnailSize:dp(50)
            Layout.fillWidth: true
            Layout.preferredWidth: thumbnailSize
            Layout.preferredHeight: thumbnailSize
            Layout.maximumHeight: thumbnailSize
            Layout.maximumWidth: thumbnailSize
           radius: dp(5)
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: dp(5)

           gradient: Gradient{
               GradientStop{position: 0.0;color:thumbnailColor}
                GradientStop{position: 1.0;color:thumbnailColor2}
           }

        }

        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            AppText{
                text:trackName
                font.bold: true
                font.pixelSize:  sp(14)
                topPadding: dp(5)

            }
            AppText{
                text:artistName
                bottomPadding: dp(5)
                font.pixelSize:  sp(12)
                color: Theme.secondaryTextColor

            }
        }

        IconButton{
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: dp(40)
            Layout.preferredHeight: dp(40)
            icon:isFavorite? IconType.heart:IconType.hearto


        }


    }
}


