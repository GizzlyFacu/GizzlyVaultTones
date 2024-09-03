import QtQuick
import "../Library"
Item {
    id:root
    property alias iconSource:iconColor.source
    property alias imageWidth:root.width
    property alias imageHeight: root.height
    property alias iconBaseColor: backgroundColor.color
    Rectangle{
        id:backgroundColor
        anchors.fill: parent
        color:"gray"
        radius: 10
    }
    IconColor{
        id:iconColor
        color:"white"
        iconWidth: parent.width
        iconHeight: parent.height
    }
    Rectangle{
        id:topColor
        visible: mouseArea.containsPress ? true:false
        opacity: 0.2
        anchors.fill: parent
        color:if(mouseArea.containsPress){
                  return Qt.darker("gray")
              }else{return Qt.lighter("gray")}
        radius: 10
    }
    MouseArea{
        id:mouseArea
        anchors.fill: parent
        onClicked: console.log("aniadir nota o audio")
    }


}
