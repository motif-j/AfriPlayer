import Felgo 3.0
import QtQuick 2.0
import QtGraphicalEffects 1.0
import "../components"
import "../models"
import "../ui"

Page {
    id: root

    property alias searchTerm: searchBar.text

    onPushed: {
          searchBar.textField.forceActiveFocus()

    }

    SearchPageModel{
        id:pageModel
    }

    rightBarItem: NavigationBarItem {
        Row {
            property real backButtonWidth: dp(Theme.navigationBar.height)
            height: dp(Theme.navigationBar.height)
            width: root.width - backButtonWidth
            anchors.right: parent.right

            SearchBar {
                id: searchBar
                inputBackgroundColor: Theme.secondaryBackgroundColor
                barBackgroundColor: "transparent"
                showClearButton: false
                anchors.verticalCenter: parent.verticalCenter

                width: textField.displayText != "" ? parent.width - clearButton.width - dp(Theme.contentPadding) : parent.width
                Behavior on width {NumberAnimation{duration: 150; easing.type: Easing.InOutQuad}}

                textField.onDisplayTextChanged:{
                }// dataModel.buildModelUponSearch(textField.displayText)

                onAccepted: {
                    console.debug(searchTerm)
                    pageModel.searchForAtrack(searchTerm)
                }
            }

            AppButton {
                id: clearButton
                flat: true
                text: "Clear"
                anchors.verticalCenter: parent.verticalCenter
                horizontalMargin: 0
                textColor: Theme.textColor
                textColorPressed: Qt.darker(Theme.textColor, 1.2)
                textSize: sp(14)

                opacity: searchBar.textField.displayText != ""
                Behavior on opacity {NumberAnimation{duration: 150}}

                onClicked: {
                    searchBar.textField.focus = false
                    searchBar.textField.clear()
                }
            }
        }
    }

    AppListView {
        id: searchResultsList
        anchors.fill: parent
        anchors.topMargin: dp(40)
   highlightMoveDuration: 500
        model: pageModel.model

        delegate:  MainTracksUi{
            width: searchResultsList.width
            id:trackUi
            trackName: model.trackName
            albumName: model.albumName
            duration: model.duration
            artistName: model.artistName
            trackId: model.trackId
            isFavorite: model.isFavorite
            themeColor:  model.colors


            onClicked: {

                selectIndex(index)
            }

        }
        highlight:Rectangle{
            color: Theme.secondaryBackgroundColor
            radius: dp(5)

        }

        emptyView.children: [
            Rectangle{
                anchors.fill: parent
                color: "transparent"

                AppActivityIndicator{
                    anchors.centerIn: parent
                    visible: pageModel.isSearching
                }

                Column {
                    visible: !pageModel.isSearching
                    anchors.centerIn: parent
                    width: searchResultsList.width * 0.75
                    spacing: dp(10)

                    AppText {
                        width: parent.width
                        text: qsTr("Play what you love")
                        fontSize: 18
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                    }

                    AppText {
                        width: parent.width

                        color: Theme.secondaryTextColor
                        fontSize: 12
                        horizontalAlignment: Text.AlignHCenter
                        text: qsTr("Search for artists, songs, podcasts, and more")
                        wrapMode: Text.WordWrap
                    }
                }
            }
        ]
    }

    function handleListViewIndexUp(){
        let cIndex=searchResultsList.currentIndex
         cIndex++
        if(cIndex>tracksModel.count-1){
            cIndex=tracksModel.count-1
        }
       searchResultsList.currentIndex=cIndex


    }
    function handleListViewIndexDown(){
        let cIndex=searchResultsList.currentIndex
         cIndex--
        if(cIndex<0){
            cIndex=0
        }
        searchResultsList.currentIndex=cIndex

    }

    function selectIndex(index){
     searchResultsList.currentIndex= index
    }

}
