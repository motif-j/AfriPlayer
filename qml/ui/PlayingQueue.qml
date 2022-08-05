import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0



Item {
    id: root
    height: dp(50)

    signal clicked()
    RowLayout{
        width: root.width
        height: root.height
        spacing: dp(5)



        Column{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: dp(5)
            Layout.rightMargin: dp(5)

            AppText{
                text:"Song Title"
                font.bold: true
                fontSize: 13
                topPadding: dp(5)
                Layout.alignment: Qt.AlignHCenter

            }
            AppText{
                text:"Song Title"
                bottomPadding: dp(5)
                fontSize: 11
                color: Theme.secondaryTextColor
                Layout.alignment: Qt.AlignHCenter

            }
        }

        IconButton{
            Layout.alignment: Qt.AlignHCenter
            icon: IconType.hearto


        }



    }
    RippleMouseArea{
        width: root.width
        height: root.height

        onClicked: {
            root.clicked()
        }
    }

}
