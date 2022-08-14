import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    id:root
    property alias dispatcher: conn.target
    property var  model: dataEntry
    property int  count: dataEntry.count
    property bool doneFetching: dataEntry.doneFetching
    property int activeIndex: dataEntry.activeIndex
    property bool  loading: dataEntry.isLoading

    signal jdownkeyPressed()
    signal jupkeyPressed()
    signal jreturnkeyPressed()
    signal indexChanged(int index)

    //    property string trackName:dataEntry.trackName
    //    property string albumName: dataEntry.albumName
    //    property string duration: dataEntry.duration
    //    property string artistName: dataEntry.artistName


    TracksDataEntry{
        id:dataEntry
        onCountChanged: (count)=>{
                            // console.debug("Hey "+count)
                            //count=0
                            // root.loading=false

                        }


        onDoneFetchingChanged: {
            console.debug("done with loading")
            // doneFetching=true
        }
        onActiveIndexChanged: {

            indexChanged(dataEntry.activeIndex)
        }

        onActiveTrackIdChanged: {
            jmusicLogic.activeTrackIdChanged(dataEntry.activeTrackId)
        }
    }


    function loadMoreTracks(){

        if(!root.loading){

            //this reduces the possibility of loading data twice concurrently
            //  root.loading=true
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

    function queAll(){
         dataEntry.mLoad()
        jmusicModel.addPlaylistToQue(-1,false)

    }

}
