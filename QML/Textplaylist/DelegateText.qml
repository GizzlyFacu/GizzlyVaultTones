import QtQuick 2.15


Item {

    Rectangle{
                width: 100
                height: 100
                color:"red"
                Text{
                    anchors.centerIn: parent
                    text: model.textnote;
                    color:"white"
                }
            }
}
