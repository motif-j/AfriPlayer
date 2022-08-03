import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../components"
import "../ui"
import "../models"



Rectangle{

    id:root
    color:Theme.secondaryBackgroundColor


    RightMusicInfoModel{
        id:_rightMusicModel
        dispatcher: jmusicLogic

        onTrackClicked: function(trackId){

        }
    }


    AppFlickable{
        anchors.fill:parent
        contentHeight: _col.height
        contentWidth: _col.width


        ColumnLayout{
            id:_col
            width: root.width
            spacing: dp(5)

            Rectangle{
                Layout.maximumHeight: dp(5)
                Layout.preferredHeight: dp(5)
            }

            AppText {
                id: name
                text: qsTr("Now Playing")
                fontSize: 16
                font.bold: true
                padding: dp(5)
                Layout.alignment: Qt.AlignHCenter


            }

            RoundedImage{
                Layout.preferredWidth:  dp(120)
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight:  dp(120)
                Layout.maximumHeight: dp(120)
                fillMode: Image.Stretch
                source:"qrc:/assets/qt.png"
                radius: dp(10)

            }

            Rectangle{
                color:Theme.secondaryBackgroundColor
                Layout.preferredWidth: dp(180)
                Layout.maximumWidth: dp(180)
                Layout.preferredHeight: trackText.height
                clip: true
                Layout.alignment: Qt.AlignHCenter
                id:trackContainer

                AppText {

                    id:trackText
                    text: {
                        let trackName=jmusicModel.activeTrack["trackName"]

                        if(isUndefined(trackName)){
                            return qsTr("Unknow Track")
                        }
                        return trackName
                    }
                    horizontalAlignment: Text.Center

                    fontSize: 14
                    font.bold: true
                    topPadding: dp(10)
                    //  anchors.centerIn: parent

                    SequentialAnimation{
                        id:seqTrackAnimator
                        loops: Animation.Infinite



                        NumberAnimation {

                            target: trackText
                            property: "x"
                            duration: 2500
                            from: trackContainer.width-trackText.width
                            to:0
                            id:trackAnimatorReverse

                        }
                        NumberAnimation {

                            target: trackText
                            property: "x"
                            from: 0
                            duration: 2500
                            to:trackContainer.width-trackText.width
                            id:trackAnimatorReverse2

                        }

                    }

                    NumberAnimation {

                        target: trackText
                        property: "x"
                        duration: 10000
                        from: trackContainer.width
                        to:-trackText.width
                        loops: Animation.Infinite
                        id:trackAnimator
                    }

                    Component.onCompleted: {
                        console.log(""+ trackContainer.width +" "+trackText.width)

                        let trackW=trackText.width
                        let contW=trackContainer.width


                        if(trackW>=contW){
                            trackAnimator.start()
                        }else{
                            trackText.width=contW

                            //seqTrackAnimator.start()
                        }
                    }
                }
            }


            AppText {

                text: {
                    let artistName=jmusicModel.activeTrack["artistName"]
                    if(isUndefined(artistName)){
                        return qsTr("Unknown Artist")
                    }

                    return artistName

                }

                fontSize: 12
                color: Theme.secondaryTextColor

                Layout.maximumWidth: dp(180)
                Layout.alignment: Qt.AlignHCenter



            }

            AppSlider{
                Layout.maximumWidth:  dp(200)
                Layout.alignment: Qt.AlignHCenter
                trackColor:JColors.pink100
                knobColor: JColors.purple100
            }
            AppText {
                id:timerText
                text:{

                    let duration=jmusicModel.activeTrack["duration"]

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

                Layout.maximumWidth: dp(180)
                Layout.alignment: Qt.AlignHCenter



            }

            PlayerBarController{
                Layout.maximumWidth: dp(220)
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumHeight: dp(50)
                Layout.preferredHeight: dp(50)

            }
            PlayerBar2{
                Layout.maximumWidth: dp(220)
                Layout.alignment: Qt.AlignHCenter
                Layout.maximumHeight: dp(50)
                Layout.preferredHeight: dp(50)

            }

            Rectangle{
                color: JColors.purple100
                height: dp(1)
                Layout.fillWidth: true
            }
            Rectangle{
                Layout.maximumHeight: dp(20)
                Layout.preferredHeight: dp(20)
            }

            AppText {

                text: qsTr("Playing Queue")
                fontSize:16
                font.bold: true
                padding: dp(5)
                Layout.alignment: Qt.AlignHCenter


            }

            AppListView{
                id:queueList
                Layout.preferredHeight: dp(80)
                Layout.preferredWidth: dp(200)
                Layout.minimumHeight: dp(300)
                Layout.alignment: Qt.AlignHCenter
                Layout.rightMargin: dp(10)
                Layout.leftMargin: dp(10)
                interactive: false
                emptyText.text: "No tracks in que"

                delegate:Item {
                    id: queueItem
                    width: queueList.width
                    height: dp(50)
                    PlayingQueue{
                        width: parent.width
                        height: parent.height
                        onClicked: {
                            queueList.currentIndex=index
                        }

                    }
                }

                highlight:Rectangle{
                    color:Theme.backgroundColor
                    radius: dp(5)


                }

            }



            Rectangle{
                Layout.fillHeight: true
                Layout.fillWidth: true
                color:Theme.backgroundColor
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
