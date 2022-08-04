import QtQuick 2.9
import com.afriktek.qplayer 1.0

//At All cost ensure this model is only instantiated once

Item {
    property alias dispatcher:musicModelConn.target
    property var activeTrack:({})
    property int activeTrackId: jmusicController.activeTrackId

    property var  playingTrack: ({})
    property var  playingTrackId: jmusicController.playingTrack


    JMusicController{
        id:jmusicController

        onTrackFetchedFromRepo: function(trackmap){
            activeTrack=trackmap
            setActiveTrackId(trackmap["trackId"])

        }
        onPlayingTrackFetched: function(trackMap){
           playingTrack=trackMap
        }

    }

    Connections{
        id:musicModelConn

        onTrackClicked:function(trackId){
          getTrack(trackId)

           // console.debug("Clicked "+trackId)
        }

        onTrackFetched:function(trackmap){
            //consume the event here
            activeTrack=trackmap
            setActiveTrackId(trackmap["trackId"])
        }

        onTrackPlayed:function(trackId){
           // getTrack(trackId)

            jmusicController.getPlayingTrack(trackId)
            addTrackToRecentlyClicked(trackId)

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

}
