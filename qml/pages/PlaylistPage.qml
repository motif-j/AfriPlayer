import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import QtQuick.Layouts 1.3
import "../ui"

Page {

    property string playlistTitle: "Playlist X"
    title:playlistTitle


    useSafeArea: false
    id:rootPage



    Item {
        focus: true
        Keys.onPressed: {
            console.debug("pressed")
        }
    }

    AppListView{
        id:tracksListView
        width: parent.width

        anchors.fill: parent
        anchors.margins: dp(5)
        model: 20


        spacing: dp(5)
        currentIndex: -1
        desktopScrollEnabled: true
        delegate: Rectangle{
            property int  currentIndex : index

            id:delRect
            height: dp(70)
            width: rootPage.width
            color: "#00000000"
            MainTracksUi{
                anchors.fill:delRect

            }
            RippleMouseArea{
                anchors.fill:delRect
                onClicked: {

                    tracksListView.currentIndex=currentIndex
                }
                onDoubleClicked: {
                    //playing track

                }
            }
        }
        highlight:Rectangle{
            color: Theme.secondaryBackgroundColor
            radius: dp(5)

        }




    }


    FloatingActionButton{
        icon: IconType.play
        visible: true
        backgroundColor: Theme.secondaryBackgroundColor
    }

}
