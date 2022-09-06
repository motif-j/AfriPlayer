import QtQuick 2.9
import QtQuick.Layouts 1.3
import Felgo 3.0
import QtQuick.Controls 2.5
import com.afriktek.qplayer 1.0




Rectangle{

    height: dp(80)
    width: parent.width
    color: "#00000000"
    clip: true
    property string trackName: ""
    property string artistName: ""
    property string albumName: ""
    property string duration: "13 : 12"
    property int  trackId: 0
    property bool isFavorite: false
    property string  themeColor: ""

    property int  cNavInd:mainNavigation.currentIndex

    property bool isCustomPlaylist:{
        if(cNavInd===3){
            return true
        }else{

            return false

        }

    }

    property color thumbnailColor: jappmodel.getColors(themeColor)[0]
    property color thumbnailColor2: jappmodel.getColors(themeColor)[1]
    //  property color thumbnailColor3: Qt.rgba(Math.random(155),Math.random(200),Math.random(55),1)
    id:rootRect

    signal clicked()

    RowLayout{
        anchors.fill: parent
        id:root
        spacing: dp(5)

        Rectangle{
            Layout.topMargin:  dp(5)
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            id:baseRect

            GridLayout{
                columns: 3
                width: parent.width

                Row{
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter
                    Layout.leftMargin: dp(2)
//                   RoundedImage{
//                        height: dp(60)
//                        width: dp(60)
//                        radius: dp(5)
//                        source: "image://gthumbnail/"+ themeColor
//                    }


                    Rectangle{
                        width: dp(5)
                    }

                    Column{
                        width: dp(100)
                        // height: dp(65)
                        spacing: dp(5)
                        leftPadding: dp(5)


                        AppText{
                            text:trackName
                            font.bold: true
                            fontSize: 14
                            topPadding: dp(5)
                            maximumLineCount: 1
                            width: dp(230)
                            // wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            elide: Text.ElideRight


                        }
                        AppText{
                            text:artistName
                            bottomPadding: dp(5)
                            fontSize: 12
                            color: Theme.secondaryTextColor
                            maximumLineCount: 1
                            elide: Text.ElideRight
                            width: dp(230)

                        }
                    }
                }

                AppText{
                    text:albumName
                    visible: root.width>dp(480)
                    fontSize: 14
                    Layout.fillWidth: true
                    width: dp(80)

                    Layout.alignment: Qt.AlignRight
                    // Layout.maximumWidth: dp(80)
                    Layout.preferredWidth: dp(50)
                    maximumLineCount: 1
                    elide: Text.ElideRight

                }

                AppText{
                    text:duration

                    fontSize: 16
                    font.family: Constants.lcdFont.name
                    font.letterSpacing: dp(2)
                    font.bold: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignRight
                    // Layout.maximumWidth: dp(100)
                    Layout.preferredWidth: dp(40)
                    maximumLineCount: 1
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere

                }

            }



        }

        IconButton{
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: dp(40)
            Layout.preferredHeight: dp(40)
            icon: isFavorite? IconType.heart:IconType.hearto


        }
    }


    RippleMouseArea{

        anchors.fill: parent
        acceptedButtons: Qt.RightButton | Qt.LeftButton
        onClicked: {


            if(mouse.button===Qt.RightButton){
                menu.popup()
            }

            rootRect.clicked()
            if(Theme.isAndroid){
                jmusicLogic.trackPlayed(trackId)
            }

        }
        onDoubleClicked: {
            //playing track
            jmusicLogic.playTrack(trackId)

        }
        onPressAndHold: {
            rootRect.clicked()
            menu.popup()
        }

        Menu{
            modal: true
            id:menu
            onClosed: {

                menu.close()
            }

            Action{
                text: "Play"
                onTriggered: {
                    //jmusicLogic.trackPlayed(trackId)
                    jmusicLogic.playTrack(trackId)
                    menu.close()
                }
            }
            Action{
                text: "Add to Queue"
                onTriggered: {
                    jmusicModel.addTrackToQueue(trackId)
                }
            }
            MenuSeparator {
                contentItem: Rectangle {
                    implicitWidth: menu.width
                    implicitHeight: dp(1)
                    color: "#21be2b"
                }
            }

            Action{
                text:{
                    if(!isCustomPlaylist){
                        return ""
                    }

                    return  "Remove From Playlist"
                }
                enabled: isCustomPlaylist
                onTriggered: {
                    jmusicModel.removeTrackFromPlaylist(trackId,globalPlId)
                    menu.close()
                }

            }


            Menu{
                id:plMenu
                title: {
                    if(isCustomPlaylist){
                        return ""
                    }

                    return  "Add To playlist"
                }
                enabled: !isCustomPlaylist
                onOpened: {


                    plMenuAdapter.loadPlaylists(false)



                }

                contentItem:
                    Rectangle{
                    implicitHeight: dp(300)
                    implicitWidth: dp(300)
                    color: Theme.backgroundColor
                    clip: true
                    radius: dp(5)



                    AppListView{
                        anchors.fill: parent

                        model: plMenuAdapter
                        spacing: dp(5)
                        delegate:PlaylistMenuItem{

                            title:    model.playlistName
                            plId: model.playlistId
                            themeColors:model.plcolors
                            id:plDelegate

                            RippleMouseArea{
                                anchors.fill: plDelegate
                                onClicked: {


                                    if(rootRect.trackId===0 || plDelegate.plId==0){

                                        plMenu.close()
                                        return
                                    }

                                    jmusicModel.addTrackToPlaylist(rootRect.trackId,plDelegate.plId)
                                    plMenu.close()
                                    menu.close()
                                }
                            }
                        }
                    }
                }

            }



            background: Rectangle{
                implicitWidth: dp(200)
                implicitHeight: dp(220)
                radius: dp(5)
                clip: true
                border.color: Theme.secondaryBackgroundColor
                color: Theme.backgroundColor

            }
            delegate:MenuItem{
                width:menu.width
                id:m_item

                contentItem: AppText{
                    fontSize: 14
                    color: Theme.textColor
                    text: m_item.text
                    font.bold: true
                    padding: dp(5)

                }
                background:Rectangle{
                    width:menu.width
                    radius: dp(5)
                    color: m_item.highlighted? Theme.tintColor:Theme.backgroundColor
                }



            }
        }
    }
}


