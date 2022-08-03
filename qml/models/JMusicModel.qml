import QtQuick 2.9
import com.afriktek.qplayer 1.0

//At All cost ensure this model is only instantiated once

Item {
    property alias dispatcher:musicModelConn.target
    property var activeTrack:({})


    JMusicController{
        id:jmusicController

        onTrackFetchedFromRepo: function(trackmap){

            jmusicLogic.trackFetched(trackmap)
        }

    }

    Connections{
        id:musicModelConn

        onTrackClicked:function(trackId){


            console.debug("Clicked "+trackId)
        }

        onTrackFetched:function(trackmap){
            //consume the event here
            activeTrack=trackmap
        }



    }

    function getTrack(trackId){
        jmusicController.getTrack(trackId)

    }

}
