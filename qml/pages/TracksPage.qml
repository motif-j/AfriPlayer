import QtQuick 2.0
import Felgo 3.0
import "../ui"
import "../models"
import "../logics"

Page {

    property bool isEmpty: tracksModel.count==0

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

        emptyText.text:{
            if(isEmptyList){
                if(!isLoading){
                    return "No Tracks found"
                }else{
                    return ""
                }


            }else{
            }
        }

        spacing: dp(5)
        currentIndex: -1
        desktopScrollEnabled: true


        footer: VisibilityRefreshHandler {
            canRefresh:tracksModel.count>0? !tracksModel.doneFetching:false
            onRefresh:  tracksModel.loadMoreTracks()
        }
        delegate:   MainTracksUi{
            id:trackUi
            trackName: model.trackName
            albumName: model.albumName
            duration: model.duration
            artistName: model.artistName
            trackId: model.trackId

            onClicked: {
                jmusicLogic.trackClicked(trackId)

                tracksListView.currentIndex=index
            }


        }


        highlight:Rectangle{
            color: Theme.secondaryBackgroundColor
            radius: dp(5)

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

    AppActivityIndicator{
        id:indicator
        anchors.centerIn: parent
        color:Theme.tintLightColor
        visible:tracksModel.loading && tracksModel.count==0
        iconSize: dp(40)


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
