import QtQuick 2.15


Item {
    property string text: "none"
    Rectangle{
                width: 100
                height: 100
                color:"black"
                Text{
                    anchors.centerIn: parent
                    text: model.textnote;
                    color:"white"
                }
            }
}
