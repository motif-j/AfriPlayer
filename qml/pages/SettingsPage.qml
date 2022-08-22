import QtQuick 2.9
import Felgo 3.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import "../settings"

Page {

    title: "Settings"

    id:rootPage
    anchors.fill: parent

    ListModel{
        id:pageModel

        ListElement{name:"Playback "; source:"qrc:///assets/cover.png";page:"../settings/PlaybackView.qml"}
        ListElement{name:"User Interface"; source:"qrc:///assets/cover.png"; page:"../settings/UserInterface.qml"}
        ListElement{name:"Music Library"; source:"qrc:///assets/cover.png";page:"../settings/LibraryView.qml"}
    }

    SplitView{
        anchors.fill: parent
        anchors.topMargin: dp(40)
        orientation: Qt.Horizontal


        AppListView{
            id:list
            Layout.minimumWidth: parent.width*0.25
            Layout.maximumWidth: parent.width*0.4
            Layout.margins: dp(5)
            backgroundColor: Theme.backgroundColor
            model:pageModel
            currentIndex: 0

            delegate:PreferenceItem{
                label: model.name
                src:model.source
                width: list.width

                onClicked: {

                    list.currentIndex=index
                    rightView.source=model.page
                }


            }
            highlight:Rectangle{
                color: Theme.secondaryBackgroundColor

                radius: dp(5)

            }

        }

        Loader{

            id:rightView
            sourceComponent: playbackComp
        }

    }

    Component{
        id:playbackComp
        PlaybackView{

        }
    }

//    Component{
//        id:uiComp
//        UserInterface{

//        }

//    }
//    Component{
//        id:libComp
//        LibraryView{

//        }
//    }

}
