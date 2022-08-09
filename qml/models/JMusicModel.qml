import QtQuick 2.9
import com.afriktek.qplayer 1.0

//At All cost ensure this model is only instantiated once

Item {
    property alias dispatcher:musicModelConn.target
    property var activeTrack:({})
    property int activeTrackId: jmusicController.activeTrackId

    property var  playingTrack: ({})
    property var  playingTrackId: jmusicController.playingTrack

    property bool shuffle: jmusicController.shuffle
    property int activeIndex : dataEntry.activeIndex

    signal trackClicked(int trackId)
    property var  model: dataEntry

    TracksDataEntry{
        id:dataEntry

        onActiveIndexChanged:function() {
            //\\ console.debug("INDEX "+dataEntry.activeIndex)
        }
    }


    function loadQueuedTracks(){
        dataEntry.loadQuedTracks();
    }

    JMusicController{
        id:jmusicController


        onPlayingTrackFetched: function(trackMap){
            playingTrack=trackMap
        }

    }




    Connections{
        id:musicModelConn


        onTrackFetched:function(trackmap){
            //consume the event here
            activeTrack=trackmap
            setActiveTrackId(trackmap["trackId"])
        }

        onTrackPlayed:function(trackId){
            // getTrack(trackId)
            if(trackId!==0){

                addTrackToRecentlyClicked(trackId)

                //  jmusicController.getPlayingTrack(trackId)
                playQueuedTrack(trackId)
            }else{

            }
        }
        onActiveTrackIdChanged: function(newId){

            setActiveTrackId(newId);
            // activeTrackId=newId

        }

    }


    function getTrack(trackId){
        jmusicController.getTrack(trackId)


    }

    function setActiveTrackId(trackId){
        jmusicController.trackClicked(trackId)
    }

    function addTrackToRecentlyClicked(trackId){

        jmusicController.addTrackToRecentlyPlayed(trackId)
    }

    function addTrackToPlaylist(trackId,plId){
        jmusicController.addTrackToPlaylist(trackId,plId);
    }

    function addTrackToQueue(trackId){
        jmusicController.addTrackToQue(trackId);

    }

    function playNext(){
        dataEntry.playNext()
    }
    function playPrevious(){
        dataEntry.playPrevious()
    }
    function playQueuedTrack(trackId){
        dataEntry.playQueuedTrack(trackId)
    }

    function addPlaylistToQue(playlistId,shuffle){

      dataEntry.clearPlaylist()
        jmusicController.addPlaylistToQueue(playlistId,shuffle)
    }
    function toggleShuffle(){
        jmusicController.toggleShuffle()
    }

}
