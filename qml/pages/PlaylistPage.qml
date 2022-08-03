import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import QtQuick.Layouts 1.3


import "../ui"
import "../models"

Page {

    property string playlistTitle: ""
    property int  playlistId: ({})
    property bool isLoading: true
    property bool isEmptyList: false


    title:playlistTitle


    useSafeArea: false
    id:rootPage


    PlaylistPageDataModel{
        dispatcher: appLogic
        id:dataModel
        playlistId: playlistId

        onLoadingChanged: function(loading){
            isEmptyList=dataModel.count==0
            if(loading){
                indicator.visible=true
            }else{
                indicator.visible=false
            }

            isLoading=loading
        }

        onJdownkeyPressed: {
            handleListViewIndexUp()
        }

        onJupkeyPressed: {
            handleListViewIndexDown()
        }

    }

    AppListView{
        id:tracksListView
        width: parent.width

        anchors.fill: parent
        anchors.margins: dp(5)
        model: dataModel.model
        emptyText.text: {
            if(isEmptyList){
                if(!isLoading){
                     return "No Tracks found"
                }else{
                    return ""
                }


            }else{
                return ""
            }
        }

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
                trackName: model.trackName
                albumName: model.albumName
                duration: model.duration
                artistName: model.artistName
                trackId: model.trackId
                onClicked: {
                    tracksListView.currentIndex=currentIndex
                    jmusicLogic.trackClicked(trackId)
                }

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
        text: "Refresh"
        iconLeft: IconType.refresh
        textColor: Theme.textColor
        backgroundColor: Theme.secondaryBackgroundColor
        onClicked: {

            isLoading=true
            dataModel.reloadTracks()
        }
    }

    AppActivityIndicator{
        id:indicator
        anchors.centerIn: parent
        color:Theme.tintLightColor
        visible:isLoading
        iconSize: dp(40)


    }


    //    FloatingActionButton{
    //        icon: IconType.play
    //        visible: true
    //        backgroundColor: Theme.secondaryBackgroundColor
    //    }



    Component.onCompleted: {
        appLogic.navigateToPlaylistPage(playlistTitle,playlistId)

        dataModel.loadMoreTracks()
    }

    function handleListViewIndexUp(){
        const  currentIndex=tracksListView.currentIndex
        let size=dataModel.count

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
