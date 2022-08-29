import QtQuick 2.0
import com.afriktek.qplayer 1.0

Item {
    property bool isSearching: adapter.isLoading
    property var  model: adapter

    SearchAdapter{
        id:adapter
    }


    function searchForAtrack(query){
        adapter.querySong(query);
    }

}
