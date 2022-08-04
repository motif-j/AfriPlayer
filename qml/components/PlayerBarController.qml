import QtQuick 2.9
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0


GridLayout{
    width: parent.width

    columns: 5

    signal playClicked();

    IconButton{
        icon: IconType.hearto
        Layout.fillWidth: true
        size: dp(18)
        color: JColors.purple100

    }
    IconButton{
        Layout.fillWidth: true
        icon: IconType.stepbackward
        size: dp(18)
        color: JColors.purple100
    }
    IconButton{
        icon: IconType.playcircle
        Layout.fillWidth: true
        size: dp(30)
        color: JColors.purple100
        onClicked: {
            playClicked();
        }


    }
    IconButton{
        Layout.fillWidth: true
        icon: IconType.stepforward
        size: dp(18)
        color: JColors.purple100
    }
    IconButton{
        icon: IconType.plus
        Layout.fillWidth: true
        size: dp(18)
        color: JColors.purple100


    }


}


