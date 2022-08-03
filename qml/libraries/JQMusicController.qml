pragma Singleton
import QtQuick 2.9
import com.afriktek.qplayer 1.0

QtObject {

    readonly property var musicController: JMusicController{


    }

    Component.onCompleted: {
        console.debug("QMUSIC CONTROLLER INIT")
    }
}
