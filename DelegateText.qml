import QtQuick 2.15

Item {
    id:root
    property string text: "spuops"
    property int widthX:100
    Rectangle{
        width: widthX
        height: 100
        color:"red"
        Text{
            anchors.centerIn: parent
            text: root.text;
            color:"white"
        }
    }
}
