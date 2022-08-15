import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../pages"


Item {

    property string globalPlTitle: ""
    property int globalPlId: -1
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
                        onNavigateUp:(pageTitle,playId)=> {

                                         globalPlTitle=pageTitle
                                         globalPlId=playId



                                         centerNavStack.push(playlistPage)


                                     }

                    }

                    Component{
                        id:playlistPage
                        PlaylistPage{
                            playlistId:globalPlId
                            playlistTitle:globalPlTitle


                        }


                    }


                }


            }


            NavigationItem{
                title:"Tracks"
                icon: IconType.music

                NavigationStack{


                    TracksPage{
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

                    FavoriteTracksPage{
                        anchors.fill: parent

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



