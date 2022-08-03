import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../ui" as Views
import "../models"



Page{
    navigationBarTranslucency: 1
    id:page
    anchors.fill: parent

    signal navigateUp(pageTitle:string ,playlistId:int)

    property int  columnCount: {
        if(page.width>450){
            return Theme.isPortrait?1:2
        }else{
            return 1

        }



    }


    title: ""
    useSafeArea: false
    anchors.leftMargin: dp(5)
    anchors.rightMargin: columnCount>1?dp(0):dp(5)
    //anchors.topMargin: dp(100)

    MainPageDataModel{
        id:mainPageDm
    }



    AppFlickable{
        width: page.width
        height:page.height
        contentWidth: baseGrid.width
        contentHeight: baseGrid.height


        GridLayout{
            id:baseGrid
            width: page.width
            columns: columnCount
            columnSpacing:dp(10)
            rowSpacing: dp(10)

            //Recently played tracks

            Column{
                Layout.fillWidth: true
                Layout.columnSpan: baseGrid.columns>1?2:1

                Rectangle{
                    height:Theme.isAndroid?dp(110):dp(80)
                    width: page.width
                    color: Theme.backgroundColor
                }

                Views.HomeHeader{
                    title: "Playlist you may like "
                    bold:true
                    //Layout.alignment: Qt.AlignHCenter

                }
            }


            AppListView{
                id:view
                Layout.fillWidth: true
                width: page.width
                Layout.columnSpan:baseGrid.columns>1?2:1
                Layout.preferredHeight: dp(225)
                Layout.alignment: Qt.AlignTop
                orientation: ListView.Horizontal
                spacing: dp(5)
                desktopScrollEnabled: true

                model:mainPageDm.playlistModel

                emptyText.text: "Leave this to us"
                delegate:Views.ItemPlaylist2{

                    title: model.playlistName
                    playlistId: model.playlistId

                    //title:qsTr(model)

                    onPlaylistClicked:(plTitle)=>{
                                          // dynamicModel.add("blue")

                                           appLogic.navigateToPlaylistPage(plTitle,playlistId)

                                          navigateUp(plTitle,playlistId)

                                      }

                }
                add:Transition {

                    NumberAnimation {

                        property: "x"
                        duration: 500
                        easing.type: Easing.InOutQuad
                        from:-view.width
                    }
                }


            }

            //

            Rectangle{
                id:rect
                Layout.fillWidth: true
                //   Layout.leftMargin:  dp(5)
                // Layout.rightMargin: columnCount>1?dp(0):dp(5)
                height: dp(380)

                color: Theme.backgroundColor
                //Playing Que

                AppListView{
                    width:rect.width

                    id:recentList
                    interactive: false
                    //model:5
                    emptyText.text: "No tracks found"
                    clip: true
                    desktopScrollEnabled: true
                    header: Views.HomeHeader{
                        anchors.margins: dp(5)
                        title:"Recently Played"
                        bold:true

                    }


                    delegate: Rectangle{
                        width: parent.width
                        height: dp(70)
                        color: "#00000000"

                        Views.HomeTracksView{
                            width:parent.width

                        }
                        RippleMouseArea{
                            width:parent.width
                            height: dp(70)
                            onClicked: {
                                console.debug("Clicked" +index)
                                recentList.currentIndex=index
                            }
                        }
                    }
                    highlight:Rectangle{
                        color: Theme.secondaryBackgroundColor
                        radius: dp(5)


                    }

                }
            }
            Rectangle{
                Layout.fillWidth: true
                height: dp(380)
                //   Layout.rightMargin:dp(2.5)
                color: Theme.backgroundColor


                //AI based playlist
                GridLayout {
                    height: parent.height
                    width: parent.width

                    id: grid
                    columns: 2
                    columnSpacing: dp(2)

                    Views.HomeHeader{
                        anchors.margins: dp(5)
                        title:"My Playlists"
                        bold:true
                        Layout.fillWidth: true
                        Layout.columnSpan: 2
                    }

                    Views.HomePlaylistView{
                        title:"Favorite Tracks"

                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)

                        onClicked:{
                            navigateUp(title)

                        }
                    }
                    Views.HomePlaylistView{
                        title:"Most Played"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)

                        onClicked:{
                            navigateUp(title)

                        }

                    }
                    Views.HomePlaylistView{
                        title:"Least Played"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)

                        onClicked:{
                            navigateUp(title)

                        }
                    }
                    Views.HomePlaylistView{
                        title:"Newest"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)

                        onClicked:{
                            navigateUp(title)

                        }
                    }


                    //Bottom Spacer
                    Rectangle{
                        Layout.fillWidth: true
                        Layout.preferredHeight: dp(50)
                        Layout.columnSpan: 2
                        color: Theme.backgroundColor

                    }

                }



            }



        }
    }
}

