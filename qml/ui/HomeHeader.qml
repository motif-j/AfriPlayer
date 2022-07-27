import QtQuick 2.0
import Felgo 3.0



AppText{
    property string  title:" "
    property bool bold: false
    property int textSize:18


    text: title
    fontSize: sp(textSize)
    font.bold: bold


}


