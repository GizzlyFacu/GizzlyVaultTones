import QtQuick 2.15
import com.library
import QtQuick.Controls.Basic
Item {
    id:root
    property string text: "texto"
    property int widthX:100
    height: baseText.contentHeight+10
    width: widthX

    Rectangle{
        id:background
        opacity: 0
        height: baseText.contentHeight
        width: root.widthX
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        color:Qt.darker(PaletteMaster.darkGrayUI)
        radius:10
    }

    TextEdit{
        id:baseText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        width: parent.width-20
        wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere
        color: PaletteMaster.whiteText
        text:root.text//aca deberia sincronizar con el struct
        selectByMouse:true
        z:1
        onTextChanged: LibraryBackends.notes_setData(model.index, text, Qt.UserRole + 1)
    }

    MouseArea{
        id:mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        onClicked: menu.open()
    }
    Menu {
        id: menu
        y: root.y
        x:root.x
        width: 50

        MenuItem {
            text: "Delete"
            onClicked: {LibraryBackends.deleteSongNotes(index);}
        }
    }

    function configSong(){
        //future action
    }
}
