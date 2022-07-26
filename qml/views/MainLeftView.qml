import QtQuick 2.0
import "../libraries"
import com.afriktek.qplayer 1.0

Item {


    Rectangle{
        width: parent.width
        height: parent.height
        color:Constants.backgroundColor

    }
    Text {
        id: name
        text: qsTr("text Left "+Constants.backgroundColor)
    }
}
