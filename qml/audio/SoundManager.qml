import QtQuick 2.9
import QtMultimedia 5.9
import com.afriktek.qplayer 1.0

Item {
    id:root
    property string ftime:jmediaPlayer.timeElapsed
    property int trackTime:0
    property real  trackPosition:0.0
    property bool isPlaying: false
    property bool isBusy: false

    property int maxVolume:jmediaPlayer.playerVolume


    //0=playing;1=stopped;2;paused
    JAudio{
        id:jmediaPlayer
        onIsPlayingChanged: {
            root.isPlaying=jmediaPlayer.isPlaying
        }
        onCanPlayChanged: {
            isBusy=!canPlay


        }
        onPositionChanged: {


            if(position>duration){
                trackPosition=duration
            }else{
               trackPosition=position
            }

            let percP=getPercentagePlay(duration,position)

            console.debug(percP)
              if(percP>80){
                  jmusicModel.playNext()
              }

        }
        onDurationChanged: {
            trackTime=duration;
        }

        onPlayNextChanged: {
            console.debug("NExt")
            jmusicModel.playNext()
        }

    }


    function play(){
         if(isBusy){
             return;
         }

        let trackId=jmusicModel.playingTrack["trackId"]
        let url=jmusicModel.playingTrack["fileUrl"]
        jmediaPlayer.play(url,trackId)


    }


    function setVolume(newValue){

        jmediaPlayer.setVolume(newValue)
    }
    function seek(position){
       jmediaPlayer.seek(position)
    }

    function getPercentagePlay(duration,position){
        let perc=position/duration *100

        return perc;
    }


}
