pragma Singleton
import QtQuick 2.0


QtObject{

    readonly property color backgroundColor: "red"

    readonly property color transparentColor: "#00000000"

    readonly property var  lcdFont: FontLoader{
        name:"Open 24 Display St"
        source:"qrc:/assets/lcd.ttf"


    }

}
