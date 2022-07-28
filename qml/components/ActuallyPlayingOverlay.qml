import Felgo 3.0
import QtQuick 2.0
import QtQuick.Layouts 1.3


Rectangle {
    id: root

    readonly property string currentTrack: "Track Name"//soundManager.currentTrack
    property bool isTrackFavorite:true //dataModel.isFavorite(root.currentTrack)

    width: parent.width
    height: dp(Theme.navigationTabBar.height)
    visible: root.currentTrack !== undefined

    color: Theme.navigationTabBar.backgroundColor

    RowLayout{
        id: container
        height: root.height
        width: root.width
        spacing: dp(2)

        AppImage {
            id: coverImage
            Layout.preferredWidth: dp(80)
            Layout.maximumWidth: dp(100)
            Layout.maximumHeight:  root.height

            source: Qt.resolvedUrl("qrc:/assets/qt.png")
        }

        Item {
            id: textContainer
            Layout.fillWidth: true

            clip: true

            AppText {
                id: movingText
                fontSize: 13

                text: {
                    if (root.currentTrack === undefined) {
                        return ""
                    }

                    var baseText = "<b>" + root.currentTrack + "</b>"


                    return baseText
                }
            }

//            NumberAnimation {
//                target: movingText
//                property: "x"
//                duration: 6000
//                from: textContainer.width
//                to: - textContainer.width

//                loops: Animation.Infinite
//                running: true
//            }
        }

        IconButton {
            id: favoriteIcon
            Layout.fillWidth: true
            Layout.preferredWidth: dp(50)


            color: Theme.textColor
            selectedColor: Theme.secondaryTextColor
            icon: root.isTrackFavorite ? IconType.heart : IconType.hearto
            size: dp(20)

            onClicked: {

            }


            IconButton {
                id: playStopButton
                anchors { right: parent.right; rightMargin: dp(2); verticalCenter: parent.verticalCenter }

                color: Theme.textColor
                selectedColor: Theme.secondaryTextColor
                icon: IconType.play
                size: dp(20)

                onClicked: {

                }
            }

        }
        Rectangle {
            id: divider
            anchors.bottom: parent.bottom
            width: parent.width
            height: dp(1)

            color: Theme.backgroundColor
        }

    }
}
