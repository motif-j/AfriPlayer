
import Felgo 3.0
import QtQuick 2.0
import "views"
import com.afriktek.qplayer 1.0
import "components"
import "./utilities"
import "./logics"
import "./models"
import "./audio"
import "./ui"

App {


    visibility: "Maximized"

    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    uiScale: Theme.isDesktop?1.7:1.0
    onInitTheme: {
        Theme.colors.backgroundColor=JColors.backgroundColor
        Theme.colors.textColor="#ffffff"
        Theme.colors.secondaryTextColor=JColors.bluegray50
        Theme.colors.secondaryBackgroundColor=JColors.sideBarColor
        Theme.colors.tintColor=JColors.purple2

        Theme.navigationBar.backgroundColor=JColors.backgroundColor
        Theme.navigationBar.titleColor="#ffffff"

        Theme.navigationAppDrawer.backgroundColor=JColors.sideBarColor
        Theme.navigationAppDrawer.itemBackgroundColor=JColors.sideBarColor
        Theme.navigationAppDrawer.textColor=JColors.purple100
        Theme.navigationAppDrawer.activeTextColor=JColors.blueLight
        Theme.navigationAppDrawer.dividerColor=Theme.secondaryBackgroundColor


        Theme.navigationTabBar.backgroundColor=JColors.sideBarColor
        Theme.navigationTabBar.titleColor=JColors.purple100
        Theme.navigationTabBar.titlePressedColor=JColors.blueLight


        Theme.listItem.backgroundColor=Theme.backgroundColor
        Theme.listItem.badgeTextColor=Theme.textColor




        // Theme.iconFont=iconFont

    }
    // FontLoader{
    //   id:iconFont
    // name:"FontAwesome"
    //./source:"qrc:/assets/font_icon.otf"
    // }


    AppModel{
        id:jappmodel
        dispatcher: appLogic

        onMMenuClosed:{
            console.debug("closes")
        }
    }
    ColorHelper{
        id:colorHelper
    }

    AppLogics{
        id:appLogic
    }
    JMusicLogic{
        id:jmusicLogic

    }

    SoundManager{
        id:soundManager
    }

    JMusicModel{
        id:jmusicModel
        dispatcher:jmusicLogic
    }




    PlaylistAdapter{
        id:plMenuAdapter
    }

    //all key events be handled globally
    NavigationStack{
        id:baseNavStack
        focus: true
        Keys.onPressed: function(event){
            let key= event.key
            appLogic.jkeyPressed(key)

        }


        Page{
            id:mainPage
            navigationBarTranslucency: 1
            navigationBarHidden: true

            MainView{
                id:mainView


            }
        }
        Component{
            id:playerPage
            Page{
                useSafeArea: false



                PlayerView{
                    width: parent.width
                    height: parent.height

                }
            }
        }




    }






}
