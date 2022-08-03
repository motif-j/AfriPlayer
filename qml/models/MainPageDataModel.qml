import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    property var playlistModel: jplaylistModel

    JPlaylistModel{
        id:jplaylistModel
    }




    Component.onCompleted: {
        jplaylistModel.loadHomePlaylists()
    }

}
