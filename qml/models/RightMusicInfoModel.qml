import QtQuick 2.0
import com.afriktek.qplayer 1.0

Item {

    property alias  dispatcher: conn.target
    property int activeIndex : 0//dataEntry.activeIndex

    signal trackClicked(int trackId)
    property var  model: dataEntry

    QueueAdapter{
        id:dataEntry


    }


    function loadQueuedTracks(){
        dataEntry.test()
    }
}
