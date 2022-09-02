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
        onJreturnkeyPressed: {


        }

    }
    ColumnLayout{
        width:parent.width
        height: parent.height

        RowLayout{
            Layout.preferredWidth:   tracksListView.width



            AppButton{
                Layout.margins: dp(2)
                Layout.alignment: Qt.AlignHCenter
                flat:false
                radius: dp(5)
                enabled: dataModel.count>0
                text: "Play all"
                iconLeft: IconType.play
                textColor: Theme.textColor
                backgroundColor: Theme.secondaryBackgroundColor
                onClicked: {
                    dataModel.addPlaylistToQueue(false)

                }
            }
            AppButton{
                Layout.margins: dp(2)
                Layout.alignment: Qt.AlignHCenter
                flat:false
                radius: dp(5)
                enabled:  dataModel.count>0
                text: "Shuffle all"
                iconLeft: IconType.random
                textColor: Theme.textColor
                backgroundColor: Theme.secondaryBackgroundColor
                onClicked: {
                    dataModel.addPlaylistToQueue(true)


                }
            }
        }

        AppListView{
            Layout.fillHeight: true
            Layout.fillWidth: true
            id:tracksListView
            width: parent.width


            // anchors.fill: parent

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
            currentIndex:-1
            desktopScrollEnabled: true
            highlightMoveDuration: 500
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
                    isFavorite: model.isFavorite
                    themeColor:   model.colors
                    onClicked: {
                        tracksListView.currentIndex=index
                        selectIndex(index)
                    }

                }

            }
            highlight:Rectangle{
                color: Theme.secondaryBackgroundColor
                radius: dp(5)

            }


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

        dataModel.loadAiTracks()
    }

    function handleListViewIndexUp(){
        let cIndex=tracksListView.currentIndex
         cIndex++
        if(cIndex>dataModel.count-1){
            cIndex=dataModel.count-1
        }
        tracksListView.currentIndex=cIndex

       // dataModel.model.incrementIndex()
    }
    function handleListViewIndexDown(){
        let cIndex=tracksListView.currentIndex
         cIndex--
        if(cIndex<0){
            cIndex=0
        }
        tracksListView.currentIndex=cIndex
      //  dataModel.model.decrementIndex()
    }

    function selectIndex(index){
        //dataModel.model.newListIndex(index)
    }

}
