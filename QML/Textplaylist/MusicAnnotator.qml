import QtQuick 2.15

Item {
    id:root
    width: parent.width
    height: 220

    TextEdit {
        id: editor
        width: 400
        height: 300
        text: "Escribe aquí..."
        wrapMode: TextEdit.WordWrap
        font.pixelSize: 18
        color: "white"

    }
}
