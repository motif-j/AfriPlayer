import QtQuick 2.0
import QtQuick.Layouts 1.3
import Felgo 3.0




Rectangle{
    color:"#00000000"
    id: root
    height: dp(70)

    property string label: ""
    property string src: ""


    signal clicked()

    RowLayout{
        width: root.width
        height: root.height

        Icon{
            Layout.preferredHeight: dp(50)
            Layout.preferredWidth: dp(50)
            Layout.alignment: Qt.AlignVCenter
            icon: IconType.folder
           // source: src
            Layout.margins: dp(2)
           // fillMode: Image.Stretch
            //radius: dp(5)
        }

        ColumnLayout{
            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true
            spacing: dp(5)
            Layout.margins: dp(2)



            Column{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                Layout.leftMargin: dp(5)
                Layout.rightMargin: dp(5)

                AppText{
                    text:label
                    fontSize: 14
                    topPadding: dp(5)
                    Layout.alignment: Qt.AlignHCenter
                    width: root.width
                    maximumLineCount: 1
                    elide: Text.ElideRight

                }

            }

            //        IconButton{
            //            Layout.alignment: Qt.AlignHCenter
            //            icon: isFavorite?IconType.heart: IconType.hearto


            //        }



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
