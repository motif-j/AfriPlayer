import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15


import "../ui"
import "../models"

Page {


    property string playlistTitle: ""
    property int  playlistId: ({})
    property bool isLoading: true
    property bool isEmptyList: false
    property string  themeColors: ""
    navigationBarTranslucency: 1



    title:playlistTitle


    useSafeArea: false
    id:rootPage
    //    rightBarItem: NavigationBarItem {
    //        Row {
    //            property real backButtonWidth: dp(Theme.navigationBar.height)
    //            height: dp(Theme.navigationBar.height)
    //            width: rootPage.width - backButtonWidth
    //            anchors.right: parent.right

    //            SearchBar {
    //                id: searchBar
    //                inputBackgroundColor: Theme.secondaryBackgroundColor
    //                barBackgroundColor: "transparent"
    //                showClearButton: false
    //                anchors.verticalCenter: parent.verticalCenter

    //                width: textField.displayText != "" ? parent.width - clearButton.width - dp(Theme.contentPadding) : parent.width
    //                Behavior on width {NumberAnimation{duration: 150; easing.type: Easing.InOutQuad}}

    //                textField.onDisplayTextChanged:{
    //                }// dataModel.buildModelUponSearch(textField.displayText)

    //                onAccepted: {
    //                    console.debug(searchTerm)
    //                    //pageModel.searchForAtrack(searchTerm)
    //                }
    //            }

    //            AppButton {
    //                id: clearButton
    //                flat: true
    //                text: "Clear"
    //                anchors.verticalCenter: parent.verticalCenter
    //                horizontalMargin: 0
    //                textColor: Theme.textColor
    //                textColorPressed: Qt.darker(Theme.textColor, 1.2)
    //                textSize: sp(14)

    //                opacity: searchBar.textField.displayText != ""
    //                Behavior on opacity {NumberAnimation{duration: 150}}

    //                onClicked: {
    //                    searchBar.textField.focus = false
    //                    searchBar.textField.clear()
    //                }
    //            }
    //        }
    //    }


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

    Component{
        id:headerComp
        ColumnLayout{
            width: parent.width
            height:  dp(Theme.navigationBar.height)+dp(225)



            Rectangle{
                height: dp(Theme.navigationBar.height)
                width: parent.width
                color: "blue"
            }

            RowLayout{
                Layout.leftMargin: dp(10)
                Layout.rightMargin: dp(10)

                RoundedImage{
                    id:thumbnail
                    Layout.fillWidth: true
                    Layout.preferredWidth:  dp(220)
                    Layout.maximumWidth: dp(220)
                    Layout.preferredHeight: dp(220)
                    radius: dp(5)
                    fillMode: Image.Stretch

                    source: "image://gthumbnail/"+themeColors
                }

                ColumnLayout{
                    Layout.fillWidth: true
                    height: dp(220)
                    spacing: dp(5)


                    AppText{
                        fontSize: 25
                        text: playlistTitle
                        Layout.alignment: Qt.AlignTop
                        font.bold: true
                        Layout.fillHeight: true
                    }
                    AppText{
                        fontSize: 16
                        text: dataModel.count+" songs  "
                        font.bold: true
                        color: Theme.secondaryTextColor
                        Layout.fillHeight: true
                    }

                    AppText{
                        fontSize: 20
                        text: dataModel.totalTrackDuration
                        font.bold: true
                        color: Theme.secondaryTextColor
                        Layout.fillHeight: true
                        font.family:  Constants.lcdFont.name
                        font.letterSpacing: dp(5)
                    }


                    RowLayout{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        spacing: dp(2)
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
                            enabled: dataModel.count>0
                            text: "Append to Current Playlist"
                            iconLeft: IconType.plus
                            textColor: Theme.textColor
                            backgroundColor: Theme.secondaryBackgroundColor
                            onClicked: {
                                dataModel.addPlaylistToQueue(true)

                            }
                        }
                        //                        AppButton{
                        //                            Layout.margins: dp(2)
                        //                            Layout.alignment: Qt.AlignHCenter
                        //                            flat:false
                        //                            radius: dp(5)
                        //                            enabled: dataModel.isUserPlaylist
                        //                            text: "Rename"

                        //                            iconLeft: IconType.edit
                        //                            textColor: Theme.textColor
                        //                            backgroundColor: Theme.secondaryBackgroundColor
                        //                            onClicked: InputDialog.inputTextSingleLine(rootPage,"Rename Playlist",playlistTitle,
                        //                                                                       function(ok,plTitle){
                        //                                                                           if(ok){
                        //                                                                              // adapter.addPlaylist(plTitle)
                        //                                                                           }
                        //                                                                       }

                        //                                                                       )
                        //                        }
                        //                        AppButton{
                        //                            Layout.margins: dp(2)
                        //                            Layout.alignment: Qt.AlignHCenter
                        //                            flat:false
                        //                            radius: dp(5)
                        //                            enabled: dataModel.isUserPlaylist
                        //                            text: "Delete"
                        //                            iconLeft: IconType.trash
                        //                            textColor: Theme.textColor
                        //                            backgroundColor: Theme.secondaryBackgroundColor
                        //                            onClicked: {
                        //                                //dataModel.addPlaylistToQueue(true)

                        //                            }
                        //                        }

                    }

                }

            }



        }
    }

    //    ColumnLayout{
    //        width:parent.width
    //        height: parent.height

    //        RowLayout{
    //            Layout.preferredWidth:   tracksListView.width



    //            AppButton{
    //                Layout.margins: dp(2)
    //                Layout.alignment: Qt.AlignHCenter
    //                flat:false
    //                radius: dp(5)
    //                enabled: dataModel.count>0
    //                text: "Play all"
    //                iconLeft: IconType.play
    //                textColor: Theme.textColor
    //                backgroundColor: Theme.secondaryBackgroundColor
    //                onClicked: {
    //                    dataModel.addPlaylistToQueue(false)

    //                }
    //            }
    //            AppButton{
    //                Layout.margins: dp(2)
    //                Layout.alignment: Qt.AlignHCenter
    //                flat:false
    //                radius: dp(5)
    //                enabled:  dataModel.count>0
    //                text: "Shuffle all"
    //                iconLeft: IconType.random
    //                textColor: Theme.textColor
    //                backgroundColor: Theme.secondaryBackgroundColor
    //                onClicked: {
    //                    dataModel.addPlaylistToQueue(true)


    //                }
    //            }
    //        }

    LinearGradient{
        width: parent.width
        height: parent.height
        start: Qt.point(0,0)
        end:Qt.point(parent.width/2,parent.height/2)

        gradient:Gradient{
            GradientStop{position:0.0;color:JColors.sideBarColor}
            GradientStop{position:1.0;color:JColors.backgroundColor}
        }


        AppListView{
            width: parent.width
            height: parent.height
            id:tracksListView


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

            header:  headerComp




        }

        AppButton{
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.bottomMargin:dp(10)
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

    }

    Component.onCompleted: {

        appLogic.navigateToPlaylistPage(playlistTitle,playlistId,themeColors)


        dataModel.loadMoreTracks()
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
