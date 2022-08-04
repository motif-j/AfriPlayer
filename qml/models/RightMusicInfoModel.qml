import QtQuick 2.0
import com.afriktek.qplayer 1.0

Item {

    property alias  dispatcher: conn.target

    signal trackClicked(int trackId)


    Connections{
        id:conn



    }

}
