import QtQuick
import QtCore
import QtQuick.Dialogs
import Qt5Compat.GraphicalEffects
import VaultTones01
import com.library
Item {
    id:root
    width: 460
    height: 34
    TextInput{
        id:textIntro
        z:1
        width: 350
        focus: root.focus
        anchors{
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: -1
            left: parent.left
            leftMargin: 40
        }
        text:""
        color: PaletteMaster.whiteText
        clip:true
        cursorVisible: false
        font{
            pixelSize: 18
        }
        onTextChanged: startSearch()

        //Control For Escape and Initialize
        function startSearch(){
            ProxyLibrary.getTextInput(textIntro.text.toLowerCase());
        }
        Keys.onEscapePressed:{
            textIntro.focus=false;
        }
    }
    DelegateSearchBar{
        id:searchLibrary
        visible: textIntro.focus
        anchors{
            top:searchBar.bottom
            topMargin: 5
        }
        MouseArea{
            anchors.fill: parent
            onClicked: searchLibrary.visible=false
        }
    }


    Rectangle{
        id:searchBar
        color:PaletteMaster.darkGrayUI
        anchors.fill: parent
        radius:20
    }
    IconColor{
        id:searchIcon
        iconWidth: 24
        iconHeight: 24
        color:PaletteMaster.whiteText
        source:"qrc:/resources/assets/icons/search.svg"
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 11
        }
        MouseArea{
            anchors.fill: parent
            onClicked:console.log("search button pressed")
        }
    }

    IconColor{
        id:filterIcon
        iconWidth: 20
        iconHeight: 20
        color:PaletteMaster.whiteText
        source:"qrc:/resources/assets/icons/filter.svg"
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 32
        }
        MouseArea{
            anchors.fill: parent
            onClicked:console.log("filter button pressed")
        }
    }
    IconColor{
        id:plusIcon
        iconWidth: 20
        iconHeight: 20
        color:PaletteMaster.whiteText
        source:"qrc:/resources/assets/icons/plus.svg"
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 9
        }
        MouseArea{
            anchors.fill: parent
            onClicked:console.log("plus button pressed")
        }
    }
    Rectangle{
        id:separator
        color:Qt.lighter(PaletteMaster.lightGrayUI)
        width: 2
        height: 23
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 61
        }
    }
    FileDialog {
        //pasar la cancion a la libreria principal
        id: fileDialog
        title: "Select an Audio"
        currentFolder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        nameFilters: ["Audio (*.mp3 *.wav *.aac *.flac *.ogg)"]

        onAccepted: {
            //imagenxd.source = fileDialog.selectedFile // Set the selected file as the source for the Image component
        }

        onRejected: {
            console.log("No file selected")
        }
    }
}
