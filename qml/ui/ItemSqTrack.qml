import QtQuick 2.0
import Felgo 3.0
import com.afriktek.qplayer 1.0
import QtQuick.Layouts 1.3

Item {
    id:root


    Rectangle{
        height:root.height
        width: root.width
        color: "blue"

    }

    Component.onCompleted: {
        console.log("Done")
    }
}
