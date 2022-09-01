import QtQuick 2.9
import Felgo 3.0
import QtGraphicalEffects 1.15


Rectangle{
    property string themeColors: {""}

        // Qt.rgba(Math.random(0,255),Math.random(0,255),Math.random(0,255),1)
    property string title:{""}
    property int playlistId: 0
    property bool isFolder:{false}
    id:root

    signal playlistClicked(plTitle:string)
    clip: true


    color: Theme.backgroundColor
    width:dp(320)
    height: dp(220)


    RoundedImage{



        id:_parentLayout
        anchors.fill: parent
        anchors.margins: dp(5)
        radius: dp(5)
        antialiasing: true
        clip: true
        fillMode: Image.Stretch
        source: "image://gthumbnail/"+themeColors
    }


    Rectangle{
        anchors.centerIn: parent
        width: parent.width
        height: dp(100)
        clip: true
        color: "transparent"

       RoundedImage {
            id: centerColor
            source: "image://gthumbnail/"+jappmodel.getColors(themeColors)[0]

            anchors.centerIn: parent

            implicitWidth: dp(100)

            width: tText.width
            height: tText.height+dp(10)
           // source: centerColor
            radius: dp(5)
            fillMode: Image.Stretch
            opacity: 0.675
        }

//        FastBlur{
//            anchors.centerIn: parent

//            implicitWidth: dp(100)

//            width: tText.width
//            height: tText.height+dp(10)
//           // source: centerColor
//            radius: 25
//            opacity: 0.2


//        }

        AppText{
            id:tText
            text: title
            anchors.centerIn: parent
            font.pixelSize: sp(18)
            leftPadding: dp(5)
            rightPadding: dp(5)
            font.bold: true
            color: {


               let arr=jappmodel.getColors(themeColors);

                let middleColor= arr[ 0]


                return colorHelper.isLight(middleColor)?"black":Theme.textColor
            }

        }
    }





    RippleMouseArea{
        width: root.width
        height:root.height
        onClicked: {
            playlistClicked(title)
        }
    }




    Icon{
        icon:IconType.folder
        size: dp(20)
        anchors.left: parent.left
        anchors.topMargin:  dp(15)
        anchors.leftMargin: dp(5)
        visible: isFolder
        color:{


            let arr=jappmodel.getColors(themeColors);

             let middleColor= arr[ 0]


             return colorHelper.isLight(middleColor)?"black":Theme.textColor
         }
    }

}
