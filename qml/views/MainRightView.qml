import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import com.afriktek.qplayer 1.0
import "../components"
import "../ui"
import "../models"



Rectangle{


    id:root
    color:Theme.secondaryBackgroundColor


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

            Rectangle{
                Layout.preferredWidth:  dp(150)
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight:  dp(150)
                Layout.maximumHeight: dp(150)
                radius: dp(10)
                color: Theme.secondaryBackgroundColor
                RoundedImage{

                    fillMode: Image.Stretch
                    source:"qrc:/assets/qt.png"
                    radius: dp(10)
                    anchors.fill: parent

                }
                RippleMouseArea{
                    anchors.fill: parent
                    onClicked: {
                        baseNavStack.push(playerPage)
                    }
                }

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
                        let trackName=jmusicModel.playingTrack["trackName"]

                        if(isUndefined(trackName)){
                            return qsTr("Unknow Track")
                        }
                        return trackName
                    }
                    horizontalAlignment: Text.Center

                    fontSize: 14
                    font.bold: true
                    topPadding: dp(10)
                    maximumLineCount: 1
                    onTextChanged: {
                        let trackW=trackText.width
                        let contW=trackContainer.width


                        if(trackW>=contW){

                           seqTrackAnimator.start()



                        }
                    }

                     anchors.centerIn: parent

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




                }
            }


            AppText {

                text: {
                    let artistName=jmusicModel.playingTrack["artistName"]
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

            ProgressBar{
                id:progress
                Layout.maximumWidth:  dp(200)
                Layout.alignment: Qt.AlignHCenter
                height: dp(3)
                width: dp(200)
               // trackColor:JColors.pink100
               // knobColor: JColors.purple100
                from:0
                to:soundManager.trackTime
                value: soundManager.trackPosition
                background: Rectangle{
                    implicitHeight: dp(4)
                    implicitWidth: parent.width
                    radius: 3

                    color: Theme.backgroundColor
                }
                contentItem:Rectangle{

                    radius:3
                    color: Theme.tintColor
                    height: parent.height
                    width: progress.visualPosition*parent.width
                }
            }
            AppText {
                id:timerText
                text:soundManager.ftime

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
                onPlayClicked: {
                    //to be implemented later
                }

            }
            PlayerBar2{
                Layout.maximumWidth: dp(220)
                Layout.alignment: Qt.AlignHCenter
              //  Layout.maximumHeight: dp(50)
                //Layout.preferredHeight: dp(50)

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
                interactive: true
                desktopScrollEnabled: true
                emptyText.text: "No tracks in que"
                model:jmusicModel.model
                currentIndex: jmusicModel.activeIndex


                delegate:Item {
                    id: queueItem
                    width: queueList.width
                    height: dp(50)
                    PlayingQueue{
                        trackName: model.trackName
                        trackId:model.trackId
                        artistName: model.artistName
                        isFavorite:model.isFavorite
                        isPlaying: model.isPlaying

                        width: parent.width
                        height: parent.height
                        onClicked: {
                            // queueList.currentIndex=index
                            jmusicModel.playQueuedTrack(trackId)
                        }

                    }
                }

                highlight:Rectangle{
                    color:"#00000000"
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
