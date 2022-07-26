import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3




//Main view thatv holds the Home View

Rectangle{
    anchors.fill: parent
    color: "gray"



    //The Row layout subdivides the view into three portions
    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 0

        MainLeftView{

            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: parent.width*0.120
            Layout.maximumWidth: parent.width*0.120
            Layout.minimumHeight: parent.height

        }
        MainCenterView {

            Layout.fillWidth: true

            Layout.minimumHeight: parent.height
        }

        MainRightView {

            Layout.fillWidth: true
            Layout.preferredWidth: parent.width*0.20
            Layout.maximumWidth: parent.width*0.20
            Layout.minimumHeight: parent.height

        }
    }

}
