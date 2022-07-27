import Felgo 3.0
import QtQuick 2.0
import "views"
import com.afriktek.qplayer 1.0


App {
    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    onInitTheme: {
        Theme.colors.backgroundColor=JColors.backgroundColor
        Theme.colors.textColor="#ffffff"
        Theme.colors.secondaryTextColor=JColors.bluegray50
        Theme.colors.secondaryBackgroundColor=JColors.sideBarColor

        Theme.navigationBar.backgroundColor=JColors.backgroundColor
        Theme.navigationBar.titleColor="#ffffff"

        Theme.navigationAppDrawer.backgroundColor=JColors.sideBarColor
        Theme.navigationAppDrawer.itemBackgroundColor=JColors.sideBarColor
        Theme.navigationAppDrawer.textColor=JColors.purple100
        Theme.navigationAppDrawer.activeTextColor=JColors.pink500




       // Theme.iconFont=iconFont

    }
   // FontLoader{
     //   id:iconFont
       // name:"FontAwesome"
        //./source:"qrc:/assets/font_icon.otf"
   // }



   MainView{

   }
}
