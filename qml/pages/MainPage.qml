import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../ui"
import "../models"



Page{
    navigationBarTranslucency: 1
    navigationBarHidden: true
    id:page
    anchors.fill: parent

    signal navigateUp(pageTitle:string ,playlistId:int,themeColor:string)


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
    anchors.rightMargin: dp(5)
    //anchors.topMargin: dp(100)

    MainPageDataModel{
        id:mainPageDm
        dispatcher:appLogic
        dispatcher2:jmusicLogic
    }





    AppFlickable{
        width: page.width
        height:page.height
        contentWidth: baseGrid.width
        contentHeight: baseGrid.height


        ColumnLayout{
            id:baseGrid
            width: page.width
            //  columns: columnCount
            //  columnSpacing:dp(10)
            // rowSpacing: dp(10)

            //Recently played tracks

            Column{
                Layout.fillWidth: true
                Layout.columnSpan: baseGrid.columns>1?2:1

                Rectangle{
                    height:dp(40)
                    width: page.width
                    color: Theme.backgroundColor
                }

               HomeHeader{
                    title: "Hello..."
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

                emptyText.text: "Please wait"
                delegate:ItemPlaylist2{

                    title: model.playlistName
                    playlistId: model.playlistId
                    isFolder:model.isFolder
                    themeColors: model.plcolors

                    //title:qsTr(model)

                    onPlaylistClicked:(plTitle)=>{
                                          // dynamicModel.add("blue")

                                          appLogic.navigateToPlaylistPage(plTitle,playlistId,themeColors)

                                          navigateUp(plTitle,playlistId,themeColors)

                                      }

                }



            }

            //

            RowLayout{
                Layout.fillWidth: true



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
                        model:mainPageDm.tracksModel
                        currentIndex: mainPageDm.tracksModel.activeIndex
                        emptyText.text: {

                            if(mainPageDm.recentTracksEmpty){
                                if(!mainPageDm.isLoading){
                                    return "Your recent Tracks will appear here"
                                }else{
                                    return ""
                                }


                            }else{
                                return ""
                            }
                        }

                        clip: true
                        desktopScrollEnabled: true
                        header: HomeHeader{
                            anchors.margins: dp(5)
                            title:"Recently Played"
                            bold:true

                        }


                        delegate: Rectangle{
                            width: rect.width
                            height: dp(70)
                            color: "#00000000"

                            MainTracksUi{
                                id:tView
                                width:parent.width
                                trackName: model.trackName
                                artistName: model.artistName
                                trackId: model.trackId
                                isFavorite: model.isFavorite
                                themeColor:  model.colors
                                duration: model.duration
                                onClicked: {
                                    selectIndex(index)
                                }




                            }
                            //                        RippleMouseArea{
                            //                            width:rect.width
                            //                            height: dp(70)
                            //                            onClicked: {
                            //                                selectIndex(index)

                            //                                if(Theme.isAndroid){
                            //                                    jmusicLogic.playTrack(tView.trackId)
                            //                                }
                            //                            }

                            //                            onDoubleClicked: {
                            //                                selectIndex(index)
                            //                                jmusicLogic.playTrack(tView.trackId)
                            //                            }
                            //                        }
                        }
                        highlight:Rectangle{
                            color: Theme.secondaryBackgroundColor
                            radius: dp(5)


                        }

                    }

                    AppActivityIndicator{
                        id:indicator
                        anchors.centerIn: parent
                        color:Theme.tintLightColor
                        visible:mainPageDm.isLoading
                        iconSize: dp(40)


                    }
                }

                Rectangle{
                    Layout.fillWidth: true
                    height: dp(380)
                    color: "transparent"

                    clip: true

                    GridView{

                        header: HomeHeader{
                            anchors.margins: dp(5)
                            title:"You may want to Look at..."
                            bold:true

                        }
                        id:grid
                        cellWidth: parent.width*0.5
                        cellHeight:dp(160)


                        model: mainPageDm.aiPlModel
                        anchors.fill:parent
                        interactive: false

                        delegate: HomePlaylistView{
                            width:grid.cellWidth
                            height: grid.cellHeight
                            title: model.playlistName
                            playlistId: model.playlistId
                            onPlaylistClicked:()=>{
                                                  let plTitle=title
                                                  // dynamicModel.add("blue")

                                                  appLogic.navigateToPlaylistPage(plTitle,playlistId,model.plcolors)

                                                  navigateUp(plTitle,playlistId,model.plcolors)

                                              }
                        }
                    }

                }

            }

            //            Rectangle{
            //                Layout.fillWidth: true
            //                height: dp(380)
            //                //   Layout.rightMargin:dp(2.5)
            //                color: Theme.backgroundColor


            //                //AI based playlist
            //                GridLayout {
            //                    height: parent.height
            //                    width: parent.width

            //                    id: grid
            //                    columns: 2
            //                    columnSpacing: dp(2)

            //                    Views.HomeHeader{
            //                        anchors.margins: dp(5)
            //                        title:"My Playlists"
            //                        bold:true
            //                        Layout.fillWidth: true
            //                        Layout.columnSpan: 2
            //                    }

            //                    Views.HomePlaylistView{
            //                        title:"Favorite Tracks"

            //                        Layout.fillWidth: true
            //                        Layout.fillHeight: true
            //                        Layout.preferredHeight: dp(150)
            //                        Layout.maximumHeight: dp(150)

            //                        onClicked:{
            //                            appLogic.navigateToPlaylistPage(title,Constants.favoritesPlaylists)

            //                            navigateUp(title,Constants.favoritesPlaylists)


            //                        }
            //                    }
            //                    Views.HomePlaylistView{
            //                        title:"Most Played"
            //                        Layout.fillWidth: true
            //                        Layout.fillHeight: true
            //                        Layout.preferredHeight: dp(150)
            //                        Layout.maximumHeight: dp(150)

            //                        onClicked:{
            //                            appLogic.navigateToPlaylistPage(title,Constants.mostPlayedPlaylists)

            //                            navigateUp(title,Constants.mostPlayedPlaylists)

            //                        }

            //                    }
            //                    Views.HomePlaylistView{
            //                        title:"Least Played"
            //                        Layout.fillWidth: true
            //                        Layout.fillHeight: true
            //                        Layout.preferredHeight: dp(150)
            //                        Layout.maximumHeight: dp(150)

            //                        onClicked:{
            //                            appLogic.navigateToPlaylistPage(title,Constants.leastPlayedPlaylists)

            //                            navigateUp(title,Constants.leastPlayedPlaylists)

            //                        }
            //                    }
            //                    Views.HomePlaylistView{
            //                        title:"Newest"
            //                        Layout.fillWidth: true
            //                        Layout.fillHeight: true
            //                        Layout.preferredHeight: dp(150)
            //                        Layout.maximumHeight: dp(150)

            //                        onClicked:{
            //                            appLogic.navigateToPlaylistPage(title,Constants.newestAddedTracks)

            //                            navigateUp(title,Constants.newestAddedTracks)

            //                        }
            //                    }


            //                    //Bottom Spacer
            //                    Rectangle{
            //                        Layout.fillWidth: true
            //                        Layout.preferredHeight: dp(50)
            //                        Layout.columnSpan: 2
            //                        color: Theme.backgroundColor

            //                    }

            //                }



            //            }



        }




    }



    function selectIndex(index){
        recentList.currentIndex=index

    }

    Component.onCompleted: {
        mainPageDm.loadPlaylists()
        mainPageDm.loadRecent()

    }
}

