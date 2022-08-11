import QtQuick 2.9
import Felgo 3.0
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3
import "../components"
import com.afriktek.qplayer 1.0

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


    Column{
        width: parent.width
        anchors.bottom:root.bottom
        anchors.bottomMargin: dp(10)

        RowLayout{
            width: parent.width


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
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: dp(10)




            }

            PlayerBarController{
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: dp(200)
                Layout.fillWidth: true
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




            }

        }

        AppSlider{
            width: parent.width

        }
    }



    function isUndefined(input){

        if(input===undefined){
            return true
        }
        return false
    }

}
