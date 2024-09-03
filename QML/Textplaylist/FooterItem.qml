import QtQuick 2.15
import "../Utilities"
import com.library

Item {
    id:root
    width: parent.width
    height: 70



    Rectangle{
        id:separator
        width: parent.width
        height: 1
        color:PaletteMaster.lightGrayText
        anchors.top: parent.top
        anchors.topMargin: 10

    }

    Item{
        width: parent.width
        height: 50
        anchors.top: parent.top
        anchors.topMargin: 20
        Rectangle {
            id:base
            opacity: 0
            anchors.fill: parent
            color:Qt.darker(PaletteMaster.lightGrayUI)
            radius:10
        }
        ImageButton{
            id:imageButton
            imageWidth: 50
            imageHeight: 50
            anchors.horizontalCenter: parent.horizontalCenter
            iconSource: "qrc:/resources/assets/icons/plus.svg"
            iconBaseColor: PaletteMaster.lightGrayUI
        }
    }
}
