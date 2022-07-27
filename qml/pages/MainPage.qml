import QtQuick 2.3
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../ui" as Views



Page{

    property int  columnCount: Theme.isPortrait?1:2

    title: "Main Page"
    useSafeArea: false
    anchors.topMargin: dp(50)
    id:page

    AppFlickable{
        anchors.fill: parent
        contentWidth: baseGrid.width
        contentHeight: baseGrid.height


        GridLayout{
            id:baseGrid
            width: page.width
            columns: columnCount
            columnSpacing:dp(10)
            rowSpacing: dp(10)
            //Recently played tracks

            Views.HomeHeader{
                title: "Daily Mix"
                bold:true
                Layout.columnSpan: baseGrid.columns>1?2:1

                //Layout.alignment: Qt.AlignHCenter

            }




            AppListView{
                Layout.fillWidth: true
                width: page.width
                Layout.columnSpan:baseGrid.columns>1?2:1
                Layout.preferredHeight: dp(200)
                Layout.alignment: Qt.AlignTop
                orientation: ListView.Horizontal
                spacing: dp(5)
                desktopScrollEnabled: true

                model:10

                delegate:Views.ItemSqTrack{

                }
                RippleMouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.debug("Clicked" +ind)
                    }
                }
            }

            //

            Rectangle{
                Layout.fillWidth: true
                height: dp(380)


                color: Theme.backgroundColor
                //Playing Que

                AppListView{
                    width: parent.width
                    height: parent.height


                    model:5
                    clip: true
                    desktopScrollEnabled: true
                    header: Views.HomeHeader{
                        anchors.margins: dp(5)
                        title:"Now Playing Que "+columnCount
                        bold:true

                    }
                    footer:Rectangle{

                        AppButton{
                            flat:true
                            text: "view all"

                        }


                    }


                    delegate: Views.HomeTracksView{
                        width:parent.width
                    }
                }
            }
            Rectangle{
                Layout.fillWidth: true
                height: dp(380)
                color: Theme.backgroundColor

                //AI based playlist

                GridLayout {
                    height: parent.height
                    width: parent.width

                    id: grid
                    columns: 2
                    columnSpacing: dp(2)

                    Views.HomeHeader{
                        anchors.margins: dp(5)
                        title:"Automated Playlists"
                        bold:true
                        Layout.fillWidth: true
                        Layout.columnSpan: 2
                    }

                    Views.HomePlaylistView{

                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)
                    }
                    Views.HomePlaylistView{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)

                    }
                    Views.HomePlaylistView{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)
                    }
                    Views.HomePlaylistView{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.preferredHeight: dp(150)
                        Layout.maximumHeight: dp(150)
                    }


                    //Bottom Spacer
                    Rectangle{
                        Layout.fillWidth: true
                        Layout.preferredHeight: dp(50)
                        Layout.columnSpan: 2
                        color: Theme.backgroundColor

                    }

                }




            }



        }
    }
}

