import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../models"




//Main view thatv holds the Home View

Rectangle{
    anchors.fill: parent
    color: Theme.backgroundColor




    //The Row layout subdivides the view into three portions
    GridLayout {

        id: layout
        anchors.fill: parent
        columns: Theme.isPortrait?1:2
        columnSpacing: dp(5)

        onColumnsChanged: {
            if(layout.columns>1){

                rightViewLoader.sourceComponent=rightViewComponent  //source= "qrc:/qml/views/MainRightView.qml"
            }else{
                rightViewLoader.sourceComponent=undefined
            }
        }

        MainCenterView {

            Layout.fillWidth: true

            Layout.fillHeight: true

        }



        Loader{
            Layout.fillWidth: true
            visible: layout.columns>1
            Layout.fillHeight: true
            Layout.minimumWidth: dp(220)
            Layout.maximumWidth: dp(280)
            id:rightViewLoader

            Component.onCompleted: {
               jmusicModel.loadQueuedTracks()
            }

        }


        Component{
            id:rightViewComponent

            MainRightView {


                anchors.fill: parent


                visible: Theme.isPortrait?false:true






            }
        }


    }

}
