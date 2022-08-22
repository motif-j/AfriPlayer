import QtQuick 2.9
import Felgo 3.0
import "./setviews"

Rectangle{
    anchors.fill: parent
    color:Theme.backgroundColor
    id:root


    AppFlickable{
       anchors.fill: parent
       contentHeight:_contColumn.height

       Column{
           id:_contColumn
           width: parent.width
           SwitchPreference{
               label: "Cross Fade Enabled "

           }
       }
    }

}
