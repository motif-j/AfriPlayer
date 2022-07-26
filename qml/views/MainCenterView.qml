import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.3
import com.afriktek.qplayer 1.0
import "../pages"


Item {


    AppPaper{
        anchors.fill: parent
        elevated: true
        radius: dp(5)
        anchors.margins: dp(5)
        shadowColor:"#00000000"


        //Children of the Main Page
        //set margins >=5 to cater for the 5dp radius

        NavigationStack{
            anchors.margins: dp(10)

            MainPage{
                anchors.fill: parent

            }
        }


    }
}



