import QtQuick 2.0
import QtMultimedia 5.9

Item {


    MediaPlayer{
        id:jmediaPlayer
        source: "G:\\CIERA\\MotifFiles\\Muhimu\\Muzik\\Music\\LuoGospel\\29nyasaye jakorwa.mp3"

       onStatusChanged: {
           console.debug("HEllo "+metaData.title)


       }
    }


    function play(){
        jmediaPlayer.play()
    }
}
