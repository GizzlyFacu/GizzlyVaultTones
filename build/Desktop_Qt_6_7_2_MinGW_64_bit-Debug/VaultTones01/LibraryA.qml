import QtQuick
import QtQuick.Controls.Basic
import VaultTones01
Item {
    readonly property Pallete paletteMaster: Pallete{}
    readonly property LibraryBackend libraryData: LibraryBackend {}
    id:root
    width: 487
    height: 367
    Rectangle{
        id:background
        anchors.fill: parent
        color: paletteMaster.lightGrayUI
    }
    Item{
        id:gridItem
        width: 487
        height: 313
        clip: true
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        Rectangle{
            id:chachos
            width: parent.width
            height: parent.height
            color:"red"
        }

        GridView{
            id:gridView
            model:libraryData
            cellWidth: 120
            cellHeight: 143
            anchors.fill: parent
            delegate:
                DelegateAlbun{
                id:delegateItem
                textInfo: songName
                albumSource: songAlbumPhoto
                x:700
                y:50
            }

            ScrollBar.vertical: ScrollBar {
                id:scrollBang
                background: Rectangle{
                    id:asdasdsd
                    color:paletteMaster.whiteBar
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    width: 15
                    height: parent.height-5
                    radius: 10



                }
                contentItem: Rectangle {
                    id:handleBar
                    implicitWidth: 15
                    implicitHeight: 10
                    radius:10
                    color: paletteMaster.darkGrayUI
                }



            }

        }

    }




    Rectangle{
        id:searchBar
        color:"grey"
        width: 460
        height: 34
        anchors.top: parent.top
    }

    Rectangle{
        id:barLat
        color:"black"
        width: 15
        height: 367
        anchors.right: parent.right
        opacity: 0
    }


}
