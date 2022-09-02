import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    id:root
    property alias dispatcher: conn.target
    property var  model: tracksAdapter
    property int  count:tracksAdapter.count
    property int playlistId: -1
    property int activeIndex: 0//dataEntry.activeIndex
    property bool doneFetching: false//dataEntry.doneFetching


    signal jdownkeyPressed()
    signal jupkeyPressed()
    signal jreturnkeyPressed()
    signal loadingChanged(bool loading)

    //    property string trackName:dataEntry.trackName
    //    property string albumName: dataEntry.albumName
    //    property string duration: dataEntry.duration
    //    property string artistName: dataEntry.artistName
    PlaylistTracksAdapter{
        id:tracksAdapter

        onIsLoadingChanged: {
            loadingChanged(tracksAdapter.isLoading)
        }
    }




    Connections{
        id:conn
        onJkeyPressed: function(key){

            switch(key){
            case Qt.Key_Down:
                jdownkeyPressed()
                break;
            case Qt.Key_Up:
                jupkeyPressed()
                break;
            case Qt.Key_Return:
                jreturnkeyPressed()
                break;

            }


        }

        onNavigateToPlaylistPage:function(title,id){
            playlistId=id


        }


    }


    function reloadTracks(){
        switch(playlistId){
        case 2:
        case 3:
        case 4:
        case 7:
            tracksAdapter.clearTracks()
            loadAiTracks()
            break;
        default:


            tracksAdapter.clearTracks()
            loadMoreTracks(1)
        }
    }

    function clearPlaylist(){
        tracksAdapter.clearTracks()
    }

    function loadMoreTracks(refresh=0){

        switch(playlistId){
        case 2:
        case 3:
        case 4:
        case 7:

            loadAiTracks()
            break

        default:



            if(!tracksAdapter.isLoading){
                //this reduces the possibility of loading data twice concurrently


                tracksAdapter.loadTracks(playlistId,refresh)
                // dataEntry.loadPlaylistTracks(playlistId,refresh)

            }else{
                console.debug("Busy")
            }
        }

    }


    function addPlaylistToQueue(shuffle){


        if(playlistId>-1){
            jmusicModel.addPlaylistToQue(playlistId,shuffle)
            tracksAdapter.addTracksToQueue(false)
        }


    }

    function loadAiTracks(){
        if(!tracksAdapter.isLoading){
            tracksAdapter.loadAiTracks(playlistId)
        }
    }


}
