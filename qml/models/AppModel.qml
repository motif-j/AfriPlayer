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
}
