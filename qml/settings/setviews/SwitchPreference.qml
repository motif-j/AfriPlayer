import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3


Item {
    property string label: ""
    width: parent.width
    height: dp(50)

    RowLayout{
        height: parent.height
        width: parent.width
        AppText{
            text: label
            fontSize: 16
            font.bold: true
            Layout.margins: dp(5)
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft|Qt.AlignVCenter

        }

        AppSwitch {
            height: dp(20)
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignRight|Qt.AlignVCenter
            // Layout.preferredWidth: dp(40)
            Layout.maximumWidth: dp(50)
            checked: jmusicModel.crossFade
            Layout.margins: dp(5)

            onToggled: {

                jmusicModel.toggleCrossFade(!checked)
            }
        }
    }


}
