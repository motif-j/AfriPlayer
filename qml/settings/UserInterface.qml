import QtQuick 2.0
import Felgo 3.0
import QtQuick.Controls 2.3
import "../ui"


Rectangle{
    anchors.fill: parent
    color:Theme.backgroundColor


    AppFlickable{
        anchors.fill: parent
        contentHeight: baseHeight.height
        anchors.margins: dp(5)

        Column{
            id:baseHeight
            width: parent.width


            HomeHeader{
                title:"App Theme"
                bold: true
                color: Theme.tintColor
            }
           Rectangle{
               color: "#00000000"
               width: dp(15)
               height:dp(15)
           }
            AppRadio{
                id:rdDark
                text: "Dark"

            }
            AppRadio{
                id:rdLight
                text: "Light"

            }

            ButtonGroup{
                id:themeButton
                buttons: [ rdDark,rdLight ]
            }
        }

    }


}


