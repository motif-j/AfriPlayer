import QtQuick 2.0
import Felgo 3.0



AppPaper {
    property string  src : ""

    radius: Math.min(baseImage.height,baseImage.width)/2
    elevated: false
    shadowColor: "#00000000"

    RoundedImage{
        id:baseImage
        anchors.fill: parent
        source: src
        fillMode: Image.Stretch
        radius:Math.min(height,width)/2
    }

    RippleMouseArea{
        anchors.fill: parent
        anchors.margins: dp(2)
    }

}
