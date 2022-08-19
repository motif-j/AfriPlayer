import QtQuick 2.9
import QtMultimedia 5.9
import com.afriktek.qplayer 1.0

Item {
    id:root
    property string ftime:"00:00"//jmediaPlayer.timeElapsed
    property int trackTime:0
    property real  trackPosition:0.0
    property bool isPlaying: false
    property bool isBusy: false

    property int maxVolume:80//jmediaPlayer.prefferedVolume


    //0=playing;1=stopped;2;paused
    JAudio{
        id:jmediaPlayer
        onIsPlayingChanged: {
            root.isPlaying=jmediaPlayer.isPlaying
        }

    }


    function play(){
        let trackId=jmusicModel.playingTrack["trackId"]
        let url=jmusicModel.playingTrack["fileUrl"]
        jmediaPlayer.play(url,trackId)


    }


    function setVolume(newValue){

    }
    function seek(position){

    }

    function sliderPosition(){

    }


}
