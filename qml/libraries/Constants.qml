pragma Singleton
import QtQuick 2.0


QtObject{

    readonly property color backgroundColor: "red"

    readonly property color transparentColor: "#00000000"
    readonly property int favoritesPlaylists:1
      readonly property int mostPlayedPlaylists:2
      readonly property int leastPlayedPlaylists:3
     readonly property int newestAddedTracks:4

    readonly property var  lcdFont: FontLoader{
        name:"Open 24 Display St"
        source:"qrc:/assets/lcd.ttf"


    }

}
