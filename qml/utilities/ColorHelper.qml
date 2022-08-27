import QtQuick 2.0
import Felgo 3.0

Item {


    function isLight(color){

        let colorString=""+color+""
        const hex=colorString.replace("#","")
        const c_r=parseInt(hex.substr(0,2),16)
        const c_g=parseInt(hex.substr(2,2),16)
        const c_b=parseInt(hex.substr(4,2),16)

        const brightness=((c_r*299)+(c_g*587)+(c_b*114))/1000
        return brightness>155
    }

    function getTextColor(color1,color2){

        if(isLight(color1) || isLight(color2)){
            return "#000000"
        }
        return "#ffffff"
    }
}
