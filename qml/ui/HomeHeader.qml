import QtQuick 2.0
import Felgo 3.0



AppText{
    property string  title:" "
    property bool italic:false


    text: title
    fontSize: sp(20)
    font.italic: italic


}


