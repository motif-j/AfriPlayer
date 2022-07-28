import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0




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

        MainCenterView {

            Layout.fillWidth: true

            Layout.fillHeight: true

        }

        MainRightView {

            Layout.fillWidth: true

            Layout.fillHeight: true
            visible: Theme.isPortrait?false:true

            Layout.minimumWidth: dp(220)
            Layout.maximumWidth: dp(280)

        }
    }

}
