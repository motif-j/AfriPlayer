import QtQuick 2.0
import Felgo 3.0
import "../ui"
import "../models"
import "../logics"

Page {

    property bool isEmptyList: tracksModel.count==0

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
        onIndexChanged:function(newIndex){
           // tracksListView.currentIndex=newIndex
        }
    }



    AppListView{

        id:tracksListView
        width: rootPage.width
        height: rootPage.height
        model: tracksModel.model
        currentIndex: tracksModel.activeIndex
        highlightMoveDuration: 500

        emptyText.text:{
            if(isEmptyList){
                if(!tracksModel.loading){
                    return "No Tracks found"
                }else{
                    return ""
                }


            }else{
                return ""
            }
        }

        spacing: dp(5)

        desktopScrollEnabled: true


        footer: VisibilityRefreshHandler {
            canRefresh:tracksModel.count>0? !tracksModel.doneFetching:false
            onRefresh:  tracksModel.loadMoreTracks()
        }
        delegate:   MainTracksUi{
            width: tracksListView.width
            id:trackUi
            trackName: model.trackName
            albumName: model.albumName
            duration: model.duration
            artistName: model.artistName
            trackId: model.trackId


            onClicked: {
                jmusicLogic.trackClicked(trackId)
                //if(trackId)
            }

            //            Component.onCompleted: {
            //             let  activeId= jmusicModel.activeTrack["trackId"]

            //                if(activeId!==undefined){
            //                    if(activeId===trackId){
            //                        tracksListView.currentIndex=index
            //                       //  console.debug(activeId)
            //                    }


            //                }
            //            }

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

        tracksModel.model.incrementIndex()
    }

    function handleListViewIndexDown(){
        tracksModel.model.decrementIndex()
    }




}
