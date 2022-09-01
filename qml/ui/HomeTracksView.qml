import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0
import QtQuick.Controls 2.5



Rectangle{
    color:"#00000000"
    id:root
    property string trackName: ""
    property string artistName: ""
    property string albumName: ""
    property int  trackId: 0
    property bool isFavorite: false
    property string  themeColor: ""
    property bool isCustomPlaylist: false

    property color thumbnailColor: jappmodel.getColors(themeColor)[0]
    property color thumbnailColor2: jappmodel.getColors(themeColor)[1]


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
            radius: dp(5)
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: dp(5)
            source: "image://gthumbnail/"+ themeColor

        }

        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter

            AppText{
                text:trackName
                font.bold: true
                font.pixelSize:  sp(14)
                topPadding: dp(5)
                maximumLineCount: 1
                elide: Text.Right
                width: dp(200)

            }
            AppText{
                text:artistName
                bottomPadding: dp(5)
                font.pixelSize:  sp(12)
                color: Theme.secondaryTextColor
                maximumLineCount: 1
                elide: Text.Right
                width: dp(200)

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

