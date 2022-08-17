import QtQuick 2.9
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0


GridLayout{
    property bool  isFavorite: {
        if(isUndefined(jmusicModel.playingTrack["isFavorite"])){

            return false
        }

        return jmusicModel.playingTrack["isFavorite"]
    }

    width: parent.width

    columns: 5

    signal playClicked();

    IconButton{
        icon: isFavorite ?IconType.heart:IconType.hearto
        Layout.fillWidth: true
        size: dp(18)
        color: JColors.purple100
        onClicked: {
            let trackId=0
            if(!isUndefined(jmusicModel.playingTrack["trackId"])){
                trackId=jmusicModel.playingTrack["trackId"]
            }

            if(trackId>0){
                jmusicModel.addTrackToPlaylist(trackId,1)
            }else{
                console.debug("invalid id")
            }


        }

    }
    IconButton{
        Layout.fillWidth: true
        icon: IconType.stepbackward
        size: dp(18)
        color: JColors.purple100

        onClicked: {
            jmusicModel.playPrevious()
        }
    }
    IconButton{
        icon: soundManager.isPlaying?IconType.pause: IconType.playcircle
        Layout.fillWidth: true
        size: dp(30)
        color: JColors.purple100
        onClicked: {
            soundManager.play()
            playClicked();
        }


    }
    IconButton{
        Layout.fillWidth: true
        icon: IconType.stepforward
        size: dp(18)
        color: JColors.purple100

        onClicked: {
            jmusicModel.playNext()
        }
    }
    IconButton{
        icon: IconType.plus
        Layout.fillWidth: true
        size: dp(18)
        color: JColors.purple100


    }

    function isUndefined(input){

        if(input===undefined){
            return true
        }
        return false
    }


}


