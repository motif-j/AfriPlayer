import QtQuick 2.9
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0



Column{
    width: parent.width


    GridLayout{
        width: parent.width

        columns: 2
        columnSpacing: dp(5)

        AppButton{
            text:jmusicModel.shuffle? "Shuffle On":"Shuffle Off"

            radius: dp(5)
            borderColor: JColors.purple100

            onClicked: {
                jmusicModel.toggleShuffle()
            }

        }
        AppButton{
            text: "Repeat one"

            radius: dp(5)
            borderColor: JColors.purple100

        }



    }

    RowLayout{
        AppText {
            id:volmeText
            text:Math.floor(control.value)

            fontSize: 13
            font.family:  Constants.lcdFont.name
            font.letterSpacing: dp(5)
            antialiasing: true

            color: Theme.secondaryTextColor
            padding: dp(2)
            Layout.preferredWidth:  dp(20)
            Layout.alignment: Qt.AlignVCenter
        }
        AppSlider{
            id:control
            Layout.fillWidth: true
            from: 0
            Layout.maximumWidth: dp(180)
              Layout.alignment: Qt.AlignVCenter
            Layout.margins: dp(2)
            to:200
            value: soundManager.maxVolume
            onMoved: {
                soundManager.setVolume(control.value)
            }

        }
        Icon{

            icon:IconType.volumeup
            Layout.maximumWidth: dp(20)
              Layout.alignment: Qt.AlignVCenter
        }

    }

}
