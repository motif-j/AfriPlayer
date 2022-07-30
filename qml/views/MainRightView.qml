import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../components"
import "../ui"



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
                fontSize: sp(20)
                font.bold: true
                padding: dp(5)
                Layout.alignment: Qt.AlignHCenter


            }

            RoundedImage{
                Layout.preferredWidth:  dp(150)
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight:  dp(150)
                Layout.maximumHeight: dp(150)
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
                    text: qsTr("Song title ")
                    fontSize: sp(16)
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
                            seqTrackAnimator.start()
                        }
                    }
                }
            }


            AppText {

                text: qsTr("Artist")
                fontSize: sp(14)
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
                text: qsTr("13 : 05 : 29")
                fontSize: sp(20)
                font.family:  Constants.lcdFont.name
                font.letterSpacing: dp(3)
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
                fontSize: sp(18)
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
                model:5

                delegate:Item {
                    id: queueItem
                    width: queueList.width
                    height: dp(50)
                    PlayingQueue{
                        width: parent.width
                        height: parent.height
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

}
