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
    property string fduration: "00:00"

    property int maxVolume:jmediaPlayer.playerVolume
    property var  playingTrack: jmediaPlayer.playingTrackVar
    property int repeatMode: jmusicModel.repeateMode


    //0=playing;1=stopped;2;paused
    JAudio{
        id:jmediaPlayer

        onTrackLengthChanged: {

            fduration=trackLength
        }

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

            if(initiatePlayNext(duration,position)){
                if(repeatMode===1){

                    let t=jmusicModel.playingTrack
                    if(t===undefined){
                        return
                    }

                    let id=t["trackId"]
                    jmusicLogic.playTrack(id)



                }else{

                    jmusicModel.playNext()
                }

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
        if(jmediaPlayer.playingId===0){

            let t=jmusicModel.playingTrack
            if(t===undefined){
                return
            }

            let id=t["trackId"]

            jmusicLogic.playTrack(id)
        }else{

            if(isBusy){
                console.debug("Engine is busy")
                return;
            }
            if(isPlaying){
                jmediaPlayer.pause()
            }else{
                jmediaPlayer.resume()
            }

            console.debug("ID id "+jmediaPlayer.playingId)
        }
        //        let trackId=jmusicModel.playingTrack["trackId"]
        //        let url=jmusicModel.playingTrack["fileUrl"]
        //        jmediaPlayer.play(url,trackId)


    }


    function setVolume(newValue){

        jmediaPlayer.setVolume(newValue)
    }
    function seek(position){

        jmediaPlayer.seek(position)



    }

    function initiatePlayNext(duration,position){

        let diff=duration-position

        if(duration>20000){
            return diff<2000;
        }

        let perc=(position/duration) *100

        return perc>98

    }

    function getPercentagePlay(duration,position){

        let perc=position/duration *100

        return perc;
    }


}
