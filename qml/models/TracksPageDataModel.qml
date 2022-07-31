import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    property alias dispatcher: conn.target
    property var  model: dataEntry
    property int  count: dataEntry.count
    property bool doneFetching: dataEntry.doneFetching

    property bool  isLoading: false

    signal jdownkeyPressed()
    signal jupkeyPressed()
    signal jreturnkeyPressed()

    //    property string trackName:dataEntry.trackName
    //    property string albumName: dataEntry.albumName
    //    property string duration: dataEntry.duration
    //    property string artistName: dataEntry.artistName

    TracksDataEntry{
        id:dataEntry
        onCountChanged: (count)=>{
                            // console.debug("Hey "+count)
                            //count=0
                            isLoading=false

                        }


        onDoneFetchingChanged: {
            console.debug("done with loading")
            // doneFetching=true
        }
    }


    function loadMoreTracks(){

        if(!isLoading){
            //this reduces the possibility of loading data twice concurrently
            isLoading=true
            dataEntry.loadMoreTracks()
        }else{
            console.debug("Busy")
        }


    }


    Component.onCompleted: {
        loadMoreTracks()

    }

    Connections{
        id:conn
        onJkeyPressed: function(key){

            switch(key){
            case Qt.Key_Down:
                jdownkeyPressed()
                break;
            case Qt.Key_Up:
                jupkeyPressed()
                break;
            case Qt.Key_Return:
                jreturnkeyPressed()
                break;

            }


        }


    }

}
