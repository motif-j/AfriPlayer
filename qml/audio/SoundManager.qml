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

    property int maxVolume:jmediaPlayer.prefferedVolume

    JAudio{
        id:jmediaPlayer
        playerVolume: volumeGhost.width

        onPrefferedVolumeChanged:  {
           // console.debug(prefferedVolume)
        }

        onPositionChanged: {

            trackPosition=position

        }

        onDurationChanged: {
            trackTime=duration
        }
        onIsPlayingChanged: {
            root.isPlaying=jmediaPlayer.isPlaying

            if(isPlaying && !isBusy){
                if(jmediaPlayer.playerVolume===0){
                    volumeAnim.from=0
                    volumeAnim.to=maxVolume

                    volumeAnim.start()
                }
            }

        }
        onPlayerVolumeChanged: {

            if(playerVolume===0){
                _playSource()

            }

        }
        onMediaFinishedChanged: {
            if(mediaFinished){
                 jmusicModel.playNext()
            }


        }
    }



    function _playSource(){
        let trackId=jmusicModel.playingTrack["trackId"]
        let url=jmusicModel.playingTrack["fileUrl"]

        console.debug(jmediaPlayer.playbackStatus)

        if(trackId===jmediaPlayer.playingId){
            switch(jmediaPlayer.playbackStatus){
            case 1:
                jmediaPlayer.play(url,trackId)


                break;
            case 0:
                jmediaPlayer.pause()
                break;
            case 2:
                jmediaPlayer.resume();
            }

        }else{
            jmediaPlayer.play(url,trackId)

        }
    }

    function play(){

        if(!isBusy){



            if(jmediaPlayer.playbackStatus===1){

                _playSource()
            }else{


                if(isPlaying){

                    volumeAnim.from=maxVolume
                    volumeAnim.to=0

                    volumeAnim.start()
                }else{

                    _playSource()
                    volumeAnim.from=0
                    volumeAnim.to=maxVolume

                    volumeAnim.start()
                }
            }




            //            let url=jmusicModel.playingTrack["fileUrl"]
            //            let trackId=jmusicModel.playingTrack["trackId"]


            //            jmediaPlayer.play(url,trackId)

        }

    }


    function setVolume(newValue){
        jmediaPlayer.setVolume(newValue)
        jmediaPlayer.setPrefVolMax(newValue)
    }
    function seek(position){
        jmediaPlayer.seek(Math.floor(position));
    }

    function sliderPosition(){

    }

    Rectangle{
        id:volumeGhost
        color: "transparent"
    }


    NumberAnimation {
        target: volumeGhost
        property: "width"
        id:volumeAnim
        duration: 1000


        easing.type: Easing.Linear
        onStopped: {
            isBusy=false
        }
        onStarted: {
            isBusy=true
        }
    }
}
