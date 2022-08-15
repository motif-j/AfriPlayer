import QtQuick 2.0
import com.afriktek.qplayer 1.0

Item {
    property var  dataModel: dataEntry
    property bool isLoading: dataEntry.loading

    FolderDataEntry{
        id:dataEntry
    }


    function addFolder(path){

        dataEntry.addFolder(path)
    }
    function deleteFolder(currentIndex){
        dataEntry.deleteFolder(currentIndex)
    }
    function synchronizeLib(){

    }

}
