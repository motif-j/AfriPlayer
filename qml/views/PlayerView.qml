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
                text:{

                    let duration=jmusicModel.playingTrack["duration"]

                    if(isUndefined(duration)){
                        return "00:00:00"
                    }
                    return duration
                }

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



        AppSlider{
            id:slider
            width: controllerRow.width
            from:0
            to:soundManager.trackTime
            value: soundManager.trackPosition
            Layout.alignment: Qt.AlignHCenter|Qt.AlignBottom

            onMoved: {
                soundManager.seek(slider.value)

            }




        }
    }



    Dial{
        id:control
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: dp(10)
        from: 0
        to:100
        value: soundManager.maxVolume

//        background: Rectangle {
//              x: control.width / 2 - width / 2
//              y: control.height / 2 - height / 2
//              width: Math.max(64, Math.min(control.width, control.height))
//              height: width
//              color: "transparent"
//              radius: width / 2
//              border.color: Theme.tintColor
//              opacity: control.enabled ? 1 : 0.3
//          }

//          handle: Rectangle {
//              id: handleItem
//              x: control.background.x + control.background.width / 2 - width / 2
//              y: control.background.y + control.background.height / 2 - height / 2
//              width: 16
//              height: 16
//              color: control.pressed ? "#17a81a" : "#21be2b"
//              radius: 8
//              antialiasing: true
//              opacity: control.enabled ? 1 : 0.3
//              transform: [
//                  Translate {
//                      y: -Math.min(control.background.width, control.background.height) * 0.4 + handleItem.height / 2
//                  },
//                  Rotation {
//                      angle: control.angle
//                      origin.x: handleItem.width / 2
//                      origin.y: handleItem.height / 2
//                  }
//              ]
//          }

        onMoved: {

            soundManager.setVolume(control.value)
        }
    }


    function isUndefined(input){

        if(input===undefined){
            return true
        }
        return false
    }


}
