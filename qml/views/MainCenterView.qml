import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../pages"


Item {

    property string globalPlTitle: ""
    property int globalPlId: -1
    property string globalThemeColor: ""
    Rectangle{
        width: parent.width
        height: parent.height

        radius: dp(5)

        color: JColors.backgroundColor
        anchors.leftMargin: dp(2)
        anchors.rightMargin: dp(2)


        //Children of the Main Page
        //set margins >=5 to cater for the 5dp radius


        Navigation{
            id:mainNavigation

            navigationMode:{
                if(Theme.isAndroid ){
                    if(Theme.isPortrait){
                        return  navigationModeTabs
                    }

                    return navigationModeDrawer
                }else{

                    return navigationModeDrawer
                }
            }//fixDrawer?navigationModeDrawer:navigationModeTabs
            drawerFixed: fixDrawer()
            drawerMinifyEnabled: fixDrawer()?true:false
            headerView: Rectangle{
                height: dp(100)

                AppActivityIndicator{
                    visible: jmusicModel.isQueryingFiles


                }

            }

            NavigationItem{
                title:"Home"
                icon: IconType.home

                NavigationStack{
                    id:centerNavStack

                    MainPage{
                        anchors.fill: parent
                        onNavigateUp:(pageTitle,playId,themeColors)=> {

                                         globalPlTitle=pageTitle
                                         globalPlId=playId
                                         globalThemeColor=themeColors



                                         centerNavStack.push(playlistPage)


                                     }


                    }

                    Component{
                        id:playlistPage
                        PlaylistPage{
                            playlistId:globalPlId
                            playlistTitle:globalPlTitle
                            themeColors: globalThemeColor


                        }


                    }

                    //                    Component{
                    //                        id:aiPlaylistPage
                    //                        AiPlaylistPage{
                    //                            playlistId: globalPlId
                    //                            playlistTitle: globalPlTitle
                    //                        }
                    //                    }


                }


            }


            NavigationItem{
                title:"Tracks"
                icon: IconType.music

                NavigationStack{


                    TracksPage{
                        onPushed: {
                            globalPlId=0
                        }

                        anchors.fill: parent

                    }
                }

            }
            NavigationItem{
                title:"Search"
                icon: IconType.search

                NavigationStack{

                    SearchPage{
                        anchors.fill: parent

                    }
                }

            }
            NavigationItem{
                title:"Playlists"
                icon: IconType.list

                NavigationStack{
                    id:navStack
                    FavoriteTracksPage{

                        onNavigateUp:(pageTitle,playId,themeColors)=> {

                                         globalPlTitle=pageTitle
                                         globalPlId=playId
                                         globalThemeColor=themeColors



                                         navStack.push(playlistPage)


                                     }
                    }
                    Component{
                        id:playlistPage
                        PlaylistPage{

                            anchors.topMargin: dp(Theme.navigationBar.height)
                            onPopped: {
                                globalPlId=0
                            }
                            playlistId:globalPlId
                            playlistTitle:globalPlTitle
                            themeColors: globalThemeColor


                        }


                    }
                }

            }

            NavigationItem{
                title:"Folders"
                icon: IconType.folder

                NavigationStack{
                    id:foldernavStack
                    PlaylistFolderPage{



                        onNavigateUp:(pageTitle,playId,themeColor)=> {

                                         globalPlTitle=pageTitle
                                         globalPlId=playId
                                         globalThemeColor=themeColor

                                         foldernavStack.push(playlistPage)


                                     }
                    }
                    Component{
                        id:playlistPage
                        PlaylistPage{
                           // anchors.topMargin: dp(Theme.navigationBar.height)
                            onPopped: {
                                globalPlId=0
                            }
                            playlistId:globalPlId
                            playlistTitle:globalPlTitle
                            themeColors: globalThemeColor


                        }


                    }
                }

            }
            NavigationItem{
                title:"Settings"
                icon: IconType.gear

                NavigationStack{

                    SettingsPage{
                        anchors.fill: parent

                    }
                }

            }
        }

    }



    function fixDrawer(){
        let isDesktop=Theme.isDesktop
        let isPotrait=Theme.isPortrait

        if(Theme.isAndroid){
            return false
        }

        if(isDesktop){
            return true
        }else{
            if(isPotrait){
                return false
            }else{
                return true
            }
        }


    }
}



