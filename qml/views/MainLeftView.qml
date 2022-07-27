import QtQuick 2.9
import "../libraries"
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import Felgo 3.0

Rectangle {

    AppFlickable{
        anchors.fill: parent



        ColumnLayout{
            anchors.fill: parent
            anchors.topMargin: dp(5)
            spacing: dp(5)


            RoundedImage{
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight:  dp(120)
                Layout.preferredWidth:dp(120)
                Layout.maximumWidth: dp(120)
                Layout.maximumHeight: dp(120)
                radius: Math.min(height,width)/2
                source: "qrc:/assets/qt.png"
                fillMode: Image.Stretch
            }

            Repeater{
                model:20

                Rectangle{

                    Layout.fillWidth: true
                    height: dp(50)

                    Rectangle{
                        anchors.fill: parent
                        anchors.margins: dp(2)
                        radius:dp(5)
                        color: "orange"
                    }

                }
            }

        }

    }
}
