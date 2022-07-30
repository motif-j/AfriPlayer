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

    TracksDataEntry{
        id:tracksDataModel
        onCountChanged: (count)=>{
                            console.debug("Hey "+dynamicModel.count)


                        }
    }

    AppListView{
        id:tracksListView
        anchors.fill: parent
        model: tracksDataModel

        spacing: dp(5)
        currentIndex: -1
        desktopScrollEnabled: true
        footer: VisibilityRefreshHandler {
            canRefresh: tracksDataModel.count<50
            onRefresh: loadNewTracks.start()
        }
        delegate: Rectangle{
            property int  currentIndex : index

            id:delRect
            height: dp(70)
            width: rootPage.width
            color: "#00000000"
            MainTracksUi{
                trackName: model.trackName
                albumName: model.albumName
                duration: model.duration
                artistName: model.artistName

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

    Timer {
      // Fake loading of new tweets in background
      id: loadNewTracks
      interval: 5000
      onTriggered: {
          console.log("Call fetch here")
       // logic.addTweet("Lorem Ipsum.")
      }
    }


}
