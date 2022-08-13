import QtQuick 2.0
import com.afriktek.qplayer 1.0
import "../logics"

Item {

    property var dispatcher: appModelConn.target
    property string currentPlaylistPageTitle: ""

    signal mMenuClosed();



    Connections{
        id:appModelConn

    }


    function getColors(input){
          if(isUndefined(input)){
              let arr=["red","blue"]
              return arr
          }

        let colorArr=input.split("-");

        return colorArr
    }

    function isUndefined(input){

        if(input===undefined){
            return true
        }
        return false;
    }
}
