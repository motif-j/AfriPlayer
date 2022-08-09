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
    anchors.leftMargin: dp(5)
    anchors.rightMargin: dp(5)



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

            jmusicLogic.trackPlayed(jmusicModel.activeTrackId)
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
            isFavorite: model.isFavorite


            onClicked: {

                selectIndex(index)
            }

        }


        highlight:Rectangle{
            color: Theme.secondaryBackgroundColor
            radius: dp(5)

        }


    }


    AppButton{
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: Theme.navigationBar.height+dp(10)
        anchors.rightMargin: dp(5)
        flat:false
        radius: dp(5)
        text: "Dynamic Play "
        iconLeft: IconType.play
        textColor: Theme.textColor
        backgroundColor: Theme.secondaryBackgroundColor
        onClicked: {

           // isLoading=true

            tracksModel.queAll()

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

    function selectIndex(index){
        tracksModel.model.newListIndex(index)
    }



}
