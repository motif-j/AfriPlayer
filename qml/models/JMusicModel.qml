import QtQuick 2.9
import com.afriktek.qplayer 1.0


//At All cost ensure this model is only instantiated once

Item {
    property alias dispatcher:musicModelConn.target
    // property var activeTrack:({})
    // property int activeTrackId: jmusicController.activeTrackId

    property var  playingTrack: soundManager.playingTrack
    //   property var  playingTrackId:0

    property bool shuffle: mainController.shuffle
    //property int activeIndex : dataEntry.playingIndex

    signal trackClicked(int trackId)
    property var  model: dataEntry
    property bool isQueryingFiles: mainController.isQuering
    property bool crossFade: false
    property bool isLoading: dataEntry.isLoading
    property string thumbnailUrl: {
        if(playingTrack===undefined){

            return "image://thumbnail/00"
        }else{
            let tId=playingTrack["colors"]

            return "image://thumbnail/"+tId

        }
    }


            QueueAdapter{
                id:dataEntry

                //   onActiveIndexChanged:function() {
                //\\ console.debug("INDEX "+dataEntry.activeIndex)
                //  }
            }


        function loadQueuedTracks(){
            // dataEntry.loadQuedTracks();
            dataEntry.test()
        }

        MainController{
            id:mainController
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
                //            if(trackId!==0){

                //              //  addTrackToRecentlyClicked(trackId)

                //                //  jmusicController.getPlayingTrack(trackId)
                //                playQueuedTrack(trackId)
                //            }else{

                //            }



            }

            onPlayTrack:function(trackId){

                if(trackId!==0){
                    mainController.loadTrackToEngine(trackId)
                }
            }

            onActiveTrackIdChanged: function(newId){

                setActiveTrackId(newId);
                // activeTrackId=newId

            }

        }



        function addTrackToRecentlyClicked(trackId){

            // jmusicController.addTrackToRecentlyPlayed(trackId)
        }

        function addTrackToPlaylist(trackId,plId){
            // jmusicController.addTrackToPlaylist(trackId,plId);
        }

        function addTrackToQueue(trackId){

            mainController.addTrackToPlayingQue(trackId)

        }

        function playNext(){
            if(soundManager.isBusy){
                return
            }


            mainController.playNext()

        }
        function playPrevious(){

            if(soundManager.isBusy){
                return
            }

            mainController.playPrevious()

        }


        function addPlayingTrackToFavorite(){

            if(playingTrack===undefined){
                return
            }
            let trackId=playingTrack["trackId"]

            mainController.addTrackToPlaylist(trackId,1)

            //mainController.a
        }


        function addPlaylistToQue(playlistId,shuffle){
            dataEntry.clearTracks()
            mainController.addPlaylistToQueue(playlistId)

        }
        function toggleShuffle(){
            mainController.toggleShuffle()
            // jmusicController.toggleShuffle()
        }

        function syncAudioFiles(){
            mainController.queryAudioFiles()
            // jmusicController.syncTracks()
        }
        function toggleCrossFade(nVal){
            // jmusicController.toggleCrossfade(nVal);
        }

    }
