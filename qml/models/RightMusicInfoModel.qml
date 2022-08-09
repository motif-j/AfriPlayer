import QtQuick 2.0
import com.afriktek.qplayer 1.0

Item {

    property alias  dispatcher: conn.target
    property int activeIndex : dataEntry.activeIndex

    signal trackClicked(int trackId)
    property var  model: dataEntry

    TracksDataEntry{
        id:dataEntry

        onActiveIndexChanged:function() {
           //\\ console.debug("INDEX "+dataEntry.activeIndex)
        }
    }


    function loadQueuedTracks(){
        dataEntry.loadQuedTracks();
    }
}
