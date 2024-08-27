import QtQuick
import QtQuick.Controls.Basic
import VaultTones01
import com.library
Item {
    id:root
    width: 487
    height: 367
    Rectangle{
        id:background
        anchors.fill: parent
        color: PaletteMaster.lightGrayUI
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
            color:PaletteMaster.lightGrayUI
        }

        GridView{
            id:gridView
            model:LibraryBackends
            cellWidth: 120
            cellHeight: 143
            anchors.fill: parent
            delegate:
                DelegateAlbun{
                id:delegateItem
                textInfo: model.songName
                albumSource: model.songAlbumPhoto
                x:700
                y:50
            }

            ScrollBar.vertical: ScrollBar {
                id:scrollBang
                background: Rectangle{
                    id:asdasdsd
                    color:PaletteMaster.whiteBar
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
                    color: PaletteMaster.darkGrayUI
                }



            }

        }

    }
    MouseArea{
        anchors.fill: background
        onClicked: {
            gridItem.focus=true;

        }
    }

    SearchBar{
        id:searchBar
        anchors.top: parent.top
        z:1
    }


}
