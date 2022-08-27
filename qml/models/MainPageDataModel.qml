import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    property var playlistModel: jplaylistModel
    property int  count: dataEntry.count
    property bool  recentTracksEmpty: count==0
    property bool isLoading: dataEntry.isLoading

    property alias dispatcher: conn.target

    property var tracksModel: dataEntry

    JPlaylistModel{
        id:jplaylistModel
    }


    PlaylistTracksAdapter{
        id:dataEntry


    }


    Connections{
        id:conn
        onJkeyPressed:function(key){
            if(key===Qt.Key_Return){


            }
        }
    }

    function loadRecent(){
        dataEntry.loadTracks(-1,0)
    }

}
