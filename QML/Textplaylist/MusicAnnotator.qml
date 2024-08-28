import QtQuick 2.15
import com.library
Item {
    id:root
    width: parent.width
    height: 220

    ListView{
        id:textView
        width: 400
        height: 300
        model: LibraryBackends.modelSongNote;
        delegate:     TextEdit {
            text: model.note
            wrapMode: TextEdit.WordWrap
            font.pixelSize: 18
            color: "white"

        }
    }

/*
    TextEdit {
        id: editor
        width: 400
        height: 300
        text: "Escribe aquí..."
        wrapMode: TextEdit.WordWrap
        font.pixelSize: 18
        color: "white"

    }
    */
}
