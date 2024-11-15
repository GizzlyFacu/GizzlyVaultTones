import QtQuick 2.15
import "../Utilities"
import com.library
import QtQuick.Controls.Basic
import QtCore
import QtQuick.Dialogs
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
            onClickd: menu.open()
        }
    }

    Menu {
        id: menu
        y: imageButton.y
        x:imageButton.x
        icon{
            source: "file:///C:/Qt/6.7.2/VaultTones01/assets/icons/play.svg"
            height: 20
            width: 20
        }

        MenuItem {
            text: "Add Note..."
            icon{
                source: "file:///C:/Qt/6.7.2/VaultTones01/assets/icons/play.svg"
                height: 20
                width: 20
                color:"red"
            }
            onClicked: LibraryBackends.addsongNotes("sample text","text")
        }
        MenuItem {
            text: "Add Audio..."
            icon{
                source: "file:///C:/Qt/6.7.2/VaultTones01/assets/icons/play.svg"
                height: 20
                width: 20
                color:"red"
            }
            onClicked: fileDialog.open()
        }
        MenuItem {
            text: "Save Notes"
            icon{
                source: "file:///C:/Qt/6.7.2/VaultTones01/assets/icons/play.svg"
                height: 20
                width: 20
                color:"red"
            }
            onClicked: LibraryBackends.saveNotes()
        }
    }
    FileDialog {
        //pasar la cancion al addsongNotes
        id: fileDialog
        title: "Select an Audio"
        currentFolder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        nameFilters: ["Audio (*.mp3 *.wav *.aac *.flac *.ogg)"]

        onAccepted: {
            LibraryBackends.addsongNotes(fileDialog.selectedFile,"audio")
        }

        onRejected: {
            console.log("No file selected")
        }
    }

    function audioUrl(){

    }

}
