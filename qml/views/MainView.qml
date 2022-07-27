import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0




//Main view thatv holds the Home View

Rectangle{
    anchors.fill: parent
    color: JColors.backgroundColor



    //The Row layout subdivides the view into three portions
    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: dp(2)



        MainCenterView {

            Layout.fillWidth: true

            Layout.minimumHeight: parent.height
        }

        MainRightView {

            Layout.fillWidth: true
            Layout.preferredWidth: parent.width*0.15
            Layout.maximumWidth: parent.width*0.15
            Layout.minimumHeight: parent.height

        }
    }

}
