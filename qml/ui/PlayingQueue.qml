import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



Rectangle{

    property int  trackId: 0
    property string trackName:""
    property string artistName: ""
    property bool isFavorite: false
    property bool isPlaying:false

    id: root
    height: dp(50)

    signal clicked()

    color:isPlaying?Theme.backgroundColor:Theme.secondaryBackgroundColor
    RowLayout{
        width: root.width
        height: root.height
        spacing: dp(5)



        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: dp(5)
            Layout.rightMargin: dp(5)

            AppText{
                text:trackName
                font.bold: true
                fontSize: 12
                topPadding: dp(5)
                Layout.alignment: Qt.AlignHCenter

            }
            AppText{
                text:artistName
                bottomPadding: dp(5)
                fontSize: 11
                color: Theme.secondaryTextColor
                Layout.alignment: Qt.AlignHCenter

            }
        }

//        IconButton{
//            Layout.alignment: Qt.AlignHCenter
//            icon: isFavorite?IconType.heart: IconType.hearto


//        }



    }
    RippleMouseArea{
        width: root.width
        height: root.height

        onClicked: {
            root.clicked()
        }
    }

}
