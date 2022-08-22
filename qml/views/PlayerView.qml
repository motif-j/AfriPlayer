import QtQuick 2.9
import Felgo 3.0
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3
import "../components"
import com.afriktek.qplayer 1.0
import QtQuick.Controls 2.15

Rectangle {
    color: Theme.backgroundColor
    id:root


    AppImage{
        id:baseImg
        anchors.fill:parent
        source: "qrc:/assets/cover.png"
        smooth: true
        visible: false
    }

    FastBlur{
        anchors.fill: parent
        source: baseImg
        radius:25
    }

    Column{
        anchors.centerIn: parent
        AppText{
            text: {
                let t= jmusicModel.playingTrack["trackName"]

                if(isUndefined(t)){
                    return ""
                }

                return t

            }
            fontSize: 20
            font.bold: true
            maximumLineCount: 1
            padding: dp(10)
            horizontalAlignment: Text.Center

        }
        AppText{
            text:{
                let t= jmusicModel.playingTrack["artistName"]

                if(isUndefined(t)){
                    return ""
                }

                return t

            }
            fontSize: 14
            horizontalAlignment: Text.Center
            padding: dp(10)
            maximumLineCount: 1


        }

    }


    ColumnLayout{
        width: parent.width
        anchors.bottom:root.bottom

        anchors.bottomMargin: dp(10)

        RowLayout{
            id:controllerRow
            Layout.alignment: Qt.AlignHCenter
            spacing: dp(20)
            AppText {


                text:soundManager.ftime

                fontSize: 16
                font.letterSpacing: dp(2)
                font.family:  Constants.lcdFont.name

                antialiasing: true
                color: Theme.secondaryTextColor
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: dp(10)
                Layout.preferredWidth:dp(50)




            }

            PlayerBarController{
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: dp(200)
                Layout.fillWidth: false
            }

            AppText {
                text:soundManager.fduration

                fontSize: 16
                font.family:  Constants.lcdFont.name
                font.letterSpacing: dp(5)
                antialiasing: true
                color: Theme.secondaryTextColor
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: dp(10)
                Layout.preferredWidth: dp(50)

                Layout.fillWidth: false


            }

        }




        Slider{
            id:slider
            width: controllerRow.width
            from:0
            to:soundManager.trackTime
            value: soundManager.trackPosition
            Layout.alignment: Qt.AlignHCenter|Qt.AlignBottom

            onMoved: {
                soundManager.seek(slider.value);
            }

            background: Rectangle{
                implicitHeight: dp(4)
                implicitWidth: parent.width
                radius: 3

                color: Theme.secondaryBackgroundColor

                Rectangle{
                    height: parent.height
                     width: slider.visualPosition*parent.width
                    radius: 3

                    color: Theme.tintLightColor
                }
            }
            handle:Rectangle{
                x: slider.visualPosition*parent.width -dp(10)//slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
                y: (slider.availableHeight / 2)-dp(5)
                radius:3
                height:dp(20)
                width:dp(20)
                color: Theme.tintColor


            }



        }
    }


    function isUndefined(input){

        if(input===undefined){
            return true
        }
        return false
    }


}
