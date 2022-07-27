import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import QtQuick.Layouts 1.3

Rectangle{

    property int  ind:index

    anchors.topMargin: dp(10)
    width: dp(175)
    height: dp(205)
    color: Theme.backgroundColor

    id:delPaper

    Rectangle{
        anchors.fill: parent
        anchors.margins: dp(5)
        radius: dp(5)
        color: Theme.secondaryBackgroundColor


        ColumnLayout{
           anchors.fill: parent


            RoundedImage{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredHeight: delPaper.height
                Layout.maximumHeight: delPaper.height

                source: "qrc:/assets/qt.png"
                fillMode: Image.Stretch

            }
            AppText{
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: qsTr("Song title ")
                fontSize: sp(15)
                leftPadding: dp(5)
                maximumLineCount: 1

                elide:Text.ElideRight

            }
            AppText{
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: qsTr("Artist Name")
                fontSize: sp(13)
                leftPadding: dp(5)
                bottomPadding: dp(5)
                maximumLineCount: 1
                elide:Text.ElideRight

            }
        }
    }
}
