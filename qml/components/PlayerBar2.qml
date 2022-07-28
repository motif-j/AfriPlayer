import QtQuick 2.9
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0


GridLayout{
    width: parent.width

    columns: 2
    columnSpacing: dp(5)

    AppButton{
        text: "Shuffle off"

        radius: dp(5)
        borderColor: JColors.purple100

    }
    AppButton{
        text: "Repeat one"

        radius: dp(5)
         borderColor: JColors.purple100

    }




}


