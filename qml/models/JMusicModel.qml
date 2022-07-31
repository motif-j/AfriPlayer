import QtQuick 2.9

Item {
    property alias dispatcher:musicModelConn.target


    Connections{
        id:musicModelConn

        onTrackClicked:function(trackId){

            console.debug("Clicked "+trackId)
        }
    }

}
