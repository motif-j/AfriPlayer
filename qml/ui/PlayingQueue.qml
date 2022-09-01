import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0
import QtQuick.Controls 2.5



Rectangle{

    property int  trackId: 0
    property string trackName:""
    property string artistName: ""
    property bool isFavorite: false
    property bool isPlaying:false

    id: root
    height: dp(50)

    signal clicked()

    color:isPlaying?Theme.backgroundColor:Theme.secondaryBackgroundColor
    ColumnLayout{
        width: root.width
        height: root.height
        spacing: dp(5)



        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: dp(5)
            Layout.rightMargin: dp(5)

            AppText{
                text:trackName
                font.bold: true
                fontSize: 12
                topPadding: dp(5)
                Layout.alignment: Qt.AlignHCenter
                width: root.width
                maximumLineCount: 1
                elide: Text.ElideRight

            }
            AppText{
                text:artistName
                bottomPadding: dp(5)
                fontSize: 11
                color: Theme.secondaryTextColor
                Layout.alignment: Qt.AlignHCenter
                width: root.width
                maximumLineCount: 1
                elide: Text.ElideRight

            }
        }

//        IconButton{
//            Layout.alignment: Qt.AlignHCenter
//            icon: isFavorite?IconType.heart: IconType.hearto


//        }



    }
    RippleMouseArea{
        id:mouse
        width: root.width
        height: root.height
        acceptedButtons: Qt.LeftButton |Qt.RightButton

        onClicked: {



            if(mouse.button===Qt.RightButton){
               menu.popup()


            }else{
              jmusicLogic.playTrack(trackId)
            }



        }

        onDoubleClicked: {
            // root.clicked()
        }





        Menu{
            modal: true
            id:menu
            onClosed: {

                menu.close()
            }


            Menu{
                id:plMenu
                title:"Add To Playlist "

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


                                    if(root.trackId===0 || plDelegate.plId==0){

                                        plMenu.close()
                                        return
                                    }

                                    jmusicModel.addTrackToPlaylist(root.trackId,plDelegate.plId)
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
                implicitHeight: dp(200)
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
