import QtQuick 2.0
import Felgo 3.0
import "../ui"
import "../models"
import "../logics"

Page {


    title: "All Tracks"
    useSafeArea: false
    id:rootPage

    anchors.topMargin: dp(50)
    anchors.leftMargin: dp(10)



    TracksPageDataModel{
        id:tracksModel
        dispatcher: appLogic

        onJdownkeyPressed: {
            handleListViewIndexUp()


        }
        onJupkeyPressed:{
            handleListViewIndexDown()

        }

        onJreturnkeyPressed: {

        }
    }



    AppListView{


        id:tracksListView
        width: rootPage.width
        height: rootPage.height
        model: tracksModel.model

        emptyText.text: "No Tracks found"

        spacing: dp(5)
        currentIndex: -1
        desktopScrollEnabled: true


        footer: VisibilityRefreshHandler {
            canRefresh:tracksModel.count>0? !tracksModel.doneFetching:false
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

        id: loadNewTracks
        interval: 2000
        onTriggered: {
            console.log("Call fetch here")
            tracksModel.loadMoreTracks()
            // tracksDataModel.cpu()
            // logic.addTweet("Lorem Ipsum.")
        }
    }

    FloatingActionButton{
        icon: IconType.refresh
        visible: tracksModel.count===0
        backgroundColor: Theme.secondaryBackgroundColor
        onClicked: {
            tracksModel.loadMoreTracks()
        }
    }

    function handleListViewIndexUp(){
        const  currentIndex=tracksListView.currentIndex
        let size=tracksModel.count

        let lastIndex=size-1

        let newIndex=currentIndex+1

        if(newIndex<=lastIndex){
            tracksListView.currentIndex=newIndex

        }else{

            tracksListView.currentIndex=currentIndex
        }
    }
    function handleListViewIndexDown(){
        const  currentIndex=tracksListView.currentIndex

        let newIndex=currentIndex-1

        if(newIndex>=0){
            tracksListView.currentIndex=newIndex

        }else{
            tracksListView.currentIndex=currentIndex
        }
    }


}
