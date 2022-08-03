import QtQuick 2.9
import com.afriktek.qplayer 1.0

Item {

    id:root
    property alias dispatcher: conn.target
    property var  model: dataEntry
    property int  count: dataEntry.count
    property int playlistId: -1
    property bool doneFetching: dataEntry.doneFetching




    signal jdownkeyPressed()
    signal jupkeyPressed()
    signal jreturnkeyPressed()
    signal loadingChanged(bool loading)

    //    property string trackName:dataEntry.trackName
    //    property string albumName: dataEntry.albumName
    //    property string duration: dataEntry.duration
    //    property string artistName: dataEntry.artistName


    TracksDataEntry{
        id:dataEntry
        onCountChanged: (count)=>{
                            // console.debug("Hey "+count)
                            //count=0

                            if(count>0){

                            }



                        }
        onIsLoadingChanged:  {
            loadingChanged(dataEntry.isLoading)


        }


        onDoneFetchingChanged: {
            console.debug("done with loading")
            // doneFetching=true
        }
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

        onNavigateToPlaylistPage:function(title,id){
            playlistId=id


        }


    }


    function reloadTracks(){

        dataEntry.clearPlaylist()
        loadMoreTracks()
    }

    function loadMoreTracks(){

        if(!dataEntry.isLoading){
            //this reduces the possibility of loading data twice concurrently

            dataEntry.loadPlaylistTracks(playlistId)

        }else{
            console.debug("Busy")
        }


    }



}
