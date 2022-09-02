import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    property var playlistModel: jplaylistModel
    property int  count: dataEntry.count
    property bool  recentTracksEmpty: count==0
    property bool isLoading: dataEntry.isLoading

    property alias dispatcher: conn.target
     property alias dispatcher2: conn2.target

    property var tracksModel: dataEntry
    property var  aiPlModel: aiPlaylists

    PlaylistAdapter{


        id:jplaylistModel
    }

    PlaylistAdapter{
     id:aiPlaylists
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
    Connections{
        id:conn2
        onPlayStatChanged:function(trackId){
            dataEntry.clearTracks();
            loadRecent()
        }
    }

    function loadRecent(){
        dataEntry.loadTracks(-1,0)
    }
    function loadPlaylists(){
        jplaylistModel.loadPlaylists(true)
        aiPlaylists.loadAiPlaylists()
    }

}
