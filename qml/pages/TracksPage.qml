import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import "../ui"
Page {
    title: "All Tracks"
    anchors.fill: parent
    useSafeArea: false
    id:rootPage

    anchors.topMargin: dp(50)
    anchors.leftMargin: dp(10)

    Item {
        focus: true
        Keys.onPressed: {
            console.debug("pressed")
        }
    }

    AppListView{
        id:tracksListView
        anchors.fill: parent
        model: 20

        spacing: dp(5)
        currentIndex: 5
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
            color: JColors.deepPurple200
            radius: dp(5)


        }



    }

}
