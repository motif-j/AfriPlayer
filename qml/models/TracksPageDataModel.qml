import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    id:root
    property alias dispatcher: conn.target
    property var  model: adapter
    property int  count: adapter.count
    property bool doneFetching: adapter.doneFetching

    property bool  loading:adapter.isLoading //dataEntry.isLoading

    signal jdownkeyPressed()
    signal jupkeyPressed()
    signal jreturnkeyPressed()
    signal indexChanged(int index)

    //    property string trackName:dataEntry.trackName
    //    property string albumName: dataEntry.albumName
    //    property string duration: dataEntry.duration
    //    property string artistName: dataEntry.artistName


    TracksAdapter{
        id:adapter
    }



    function loadMoreTracks(){

        if(!root.loading){

            //this reduces the possibility of loading data twice concurrently
            //  root.loading=true
            // dataEntry.loadMoreTracks()
            adapter.loadTracks()
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
        //   dataEntry.mLoad()
        jmusicModel.addPlaylistToQue(-1,false)

    }

}
