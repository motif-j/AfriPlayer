import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

import "../ui"
import "./setviews"
import "./models"

Rectangle{
    anchors.fill: parent
    color:Theme.backgroundColor
    id:root

    FolderViewModel{
        id:viewModel
    }



    ColumnLayout{
        width: root.width

        RowLayout{

            AppButton{
                Layout.margins: dp(2)
                Layout.alignment: Qt.AlignHCenter
                flat:false
                radius: dp(5)
                text: "Add New Folder"
                iconLeft: IconType.folder
                textColor: Theme.textColor
                backgroundColor: Theme.secondaryBackgroundColor
                enabled: !viewModel.isLoading
                onClicked: {
                    folderDialog.open()
                }
            }
            AppButton{
                Layout.margins: dp(2)
                Layout.alignment: Qt.AlignHCenter
                flat:false
                radius: dp(5)
                 enabled: !viewModel.isLoading
                text: "Remove Folder"
                iconLeft: IconType.trash
                textColor: Theme.textColor
                backgroundColor: Theme.secondaryBackgroundColor
                onClicked: {

                    let cIndex=list.currentIndex
                    if(list.count>0 && cIndex!==-1){

                        viewModel.deleteFolder(cIndex)
                    }

                }
            }
            AppButton{
                Layout.margins: dp(2)
                Layout.alignment: Qt.AlignHCenter
                flat:false
                radius: dp(5)
                 enabled: !viewModel.isLoading && !jmusicModel.isQueryingFiles
                text: "Synchronize Files"
                iconLeft: IconType.refresh
                textColor: Theme.textColor
                backgroundColor: Theme.secondaryBackgroundColor
                onClicked: {

                    jmusicModel.syncAudioFiles()
                }
            }
        }

        HomeHeader{
            title:"Folders that will build up your collection"
            padding: dp(5)
            color: Theme.tintColor
            bold: true
        }

        Rectangle{
            width: root.width
            color: "#00000000"
            height: dp(300)
            border.color: Theme.tintColor
            border.width: dp(2)
            Layout.topMargin: dp(10)
            Layout.rightMargin: dp(2)
            Layout.leftMargin: dp(2)
            clip:true
            radius: dp(5)

            AppListView{
                id:list
                width: root.width
                clip: true

                model:viewModel.dataModel
                emptyText.text: qsTr("Your library seems to be empty ")
                currentIndex: 1
                delegate:FolderView{
                    src: IconType.folder
                    label: model.display
                    width: root.width
                    onClicked: {
                        list.currentIndex=index
                    }
                }

                highlight: Rectangle{

                    color:Theme.secondaryBackgroundColor
                }
            }
        }
    }


    FolderDialog{
        id:folderDialog
        folder: StandardPaths.standardLocations(StandardPaths.MusicLocation)[0]
        onAccepted: {
           viewModel.addFolder(folderDialog.currentFolder)
        }

    }
}
