import QtQuick 2.9
import Felgo 3.0
import "../ui"
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
//import QtQuick.Dialogs 1.3

Page {
    title: "Playlists"
    width: parent.width
    height: parent.height
    useSafeArea: false
    id:root

    signal navigateUp(pageTitle:string ,playlistId:int)

    PlaylistAdapter{
        id:adapter
    }




    ColumnLayout{
        anchors.fill: parent
        anchors.topMargin: dp(Theme.navigationBar.height)


        GridView{
            Layout.alignment: Qt.AlignHCenter
            Layout.fillHeight: true
            Layout.fillWidth: true

            model: adapter
            cellWidth:dp(330)
            cellHeight: dp(230)


            delegate: ItemPlaylist2{
                title: model.playlistName
                playlistId: model.playlistId
                themeColors: model.plcolors
                isFolder: model.isFolder

                //title:qsTr(model)

                onPlaylistClicked:(plTitle)=>{
                                      // dynamicModel.add("blue")

                                      appLogic.navigateToPlaylistPage(plTitle,playlistId,themeColors)

                                      navigateUp(plTitle,playlistId,themeColors)

                                  }




            }

        }

    }

    AppButton{
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: dp(10)
        radius: dp(5)
        backgroundColor: Theme.secondaryBackgroundColor
        text: "Add"
        iconLeft: IconType.plus
        onClicked: InputDialog.inputTextSingleLine(root,"Add New Playlist","Enter name here...",
                                                   function(ok,plTitle){
                                                       if(ok){
                                                           adapter.addPlaylist(plTitle)
                                                       }
                                                   }

                                                   )
    }

    Component.onCompleted: {
        adapter.loadPlaylists(false)
    }
}
