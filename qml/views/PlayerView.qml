import QtQuick 2.9
import Felgo 3.0
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3
import "../components"
import com.afriktek.qplayer 1.0
import QtQuick.Controls 2.15
import QtQuick.Particles 2.15

Rectangle {
    color: Theme.backgroundColor
    id:root
    property string themeColor: {

        let pTrack=soundManager.playingTrack
        if(pTrack===undefined){

            return ""
        }

        return pTrack["colors"]
    }

    property color color1: jappmodel.getColors(themeColor)[0]
    property color color2: jappmodel.getColors(themeColor)[1]



    ParticleSystem{
        id:particleSystem
        paused: !soundManager.isPlaying
    }


    AppImage{
        id:baseImg
        anchors.fill:parent
        fillMode: Image.Stretch
        source: {
            if(jmusicModel.playingTrack===undefined){

                return "image://playerthumbnail/00"
            }else{
                let tId=jmusicModel.playingTrack["colors"]

                return "image://playerthumbnail/"+tId

            }
        }

        smooth: true
        visible: true
    }

    Emitter{
        anchors.fill: parent
        system: particleSystem
        emitRate: 5
        lifeSpan: 5000
        lifeSpanVariation: 5000
        size:dp(50)
       endSize: dp(400)




    }
    ImageParticle{
        source: {
            if(jmusicModel.playingTrack===undefined){

                return "image://particle/00"
            }else{
                let tId=jmusicModel.playingTrack["colors"]

                return "image://particle/"+tId

            }
        }

        alpha: 0.22

        system: particleSystem

        entryEffect: ImageParticle.Fade
    }

    //    FastBlur{
    //        anchors.fill: parent
    //        source: baseImg
    //        radius:25
    //    }


    Rectangle{
        width: parent.width

        anchors.bottom:root.bottom
        anchors.bottomMargin: dp(10)
        color: "transparent"
         height:col.height



        Rectangle{

            width: col.width+dp(10)


            color: Theme.backgroundColor
            radius:dp(5)
            height:col.height
            anchors.centerIn: parent
            clip:true



            ColumnLayout{
                id:col
                AppText{
                    text: {
                        let t= jmusicModel.playingTrack["trackName"]

                        if(isUndefined(t)){
                            return ""
                        }

                        return t

                    }
                    fontSize: 16
                    font.bold: true
                   // wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                    horizontalAlignment: Text.Center
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: dp(4)
                    Layout.maximumWidth: dp(400)
                    maximumLineCount: 1
                   // color: colorHelper.getTextColor(color1,color2)
                    elide: Text.ElideRight

                }
                AppText{
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: dp(4)
                     maximumLineCount: 1
                    text:{
                        let t= jmusicModel.playingTrack["artistName"]

                        if(isUndefined(t)){
                            return ""
                        }

                        return t

                    }
                    fontSize: 14
                    horizontalAlignment: Text.Center
                     elide: Text.ElideRight
                    Layout.maximumWidth: dp(400)
                    // color: colorHelper.getTextColor(color1,color2)


                }
                RowLayout{
                    id:controllerRow
                    Layout.alignment: Qt.AlignHCenter
                    Layout.margins: dp(10)
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
                    Layout.bottomMargin: dp(10)

                    onMoved: {
                        soundManager.seek(slider.value);
                    }

                    background: Rectangle{
                        implicitHeight: dp(5)
                        implicitWidth: parent.width
                        radius: dp(5)

                        color: Theme.secondaryBackgroundColor

                        Rectangle{
                            height: parent.height
                            width: slider.visualPosition*parent.width
                            radius: dp(5)

                            LinearGradient{
                                anchors.fill: parent
                                start: Qt.point(0,parent.height/2)
                                end:Qt.point(parent.width,parent.height/2)
                                gradient: Gradient{
                                    id:_lgrid

                                    GradientStop{position: 0.0;color: Qt.lighter(color1)}
                                   // GradientStop{position: 0.25;color:Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)}
                                    GradientStop{position: 0.50;color: Qt.lighter(color2)}

                                }
                            }


                        }

                            //color: Theme.tintLightColor

                    }
                    handle:Rectangle{
                        x: slider.visualPosition*parent.width -dp(10)//slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
                        y: (slider.availableHeight / 2)-dp(5)
                        radius:dp(7.5)
                        height:dp(20)
                        width:dp(20)

                        color: {

                            let p=(slider.value/soundManager.trackTime)*100

                            if(p>50){
                                return color1
                            }

                            color2
                        }



                    }



                }
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
