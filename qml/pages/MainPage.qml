import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../ui" as Views



Page{
    title: "Main Page"
    useSafeArea: false
    anchors.topMargin: dp(45)


    ColumnLayout{
        anchors.fill: parent
        spacing: dp(10)

        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop


            Views.HomeHeader{
                title: "Recently Played"
                Layout.fillWidth: true
                //Layout.alignment: Qt.AlignHCenter

            }

            IconButton{
                icon: IconType.arrowright
                Layout.fillWidth: true
                Layout.preferredWidth: dp(50)
                Layout.maximumWidth: dp(50)
                Layout.alignment: Qt.AlignHCenter
            }

        }

        //Recently played tracks

        AppListView{
            Layout.fillWidth: true

            Layout.preferredHeight: dp(210)
            Layout.alignment: Qt.AlignTop
            orientation: AppListView.Horizontal
            spacing: dp(10)


            model:10

            delegate:AppPaper{

               property int  ind:index

                anchors.topMargin: dp(10)
                width: dp(175)
                height: dp(205)
                radius: dp(5)

                id:delPaper

                ColumnLayout{
                    width: dp(175)
                    height:delPaper.height

                    RoundedImage{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: delPaper.height
                        Layout.maximumHeight: delPaper.height

                        source: "qrc:/assets/qt.png"
                        fillMode: Image.Stretch

                    }
                    AppText{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: qsTr("Song title ")
                        fontSize: sp(15)
                        leftPadding: dp(5)
                        maximumLineCount: 1

                        elide:Text.ElideRight

                    }
                    AppText{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        text: qsTr("Artist Name")
                        fontSize: sp(13)
                         leftPadding: dp(5)
                         bottomPadding: dp(5)
                         maximumLineCount: 1
                         elide:Text.ElideRight

                    }
                }


                RippleMouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.debug("Clicked" +ind)
                    }
                }
            }

        }
        //Bottom Items

        RowLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            spacing: dp(5)


            //Left space

                   Column {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumWidth: parent.width*0.45
                    Layout.preferredWidth:  parent.width*0.45
                    anchors.leftMargin: dp(5)


                    Views.HomeHeader{
                        anchors.margins: dp(5)
                        title:"Tracks"
                    }

                    AppListView{
                        width: parent.width
                        model:20

                        delegate: Views.HomeHeader{
                            title: "text "+index
                        }
                    }


                }

            //Right space

                Rectangle {
                    color: 'plum'
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumWidth: parent.width*0.5
                    Layout.preferredWidth:  parent.width*0.5
                    Text {
                        anchors.centerIn: parent
                        text: parent.width + 'x' + parent.height
                    }
                }

        }



    }



}
