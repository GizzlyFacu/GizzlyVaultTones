import QtQuick
import VaultTones01
import com.library
Item {

    id:root
    width: 460
    height: 250
    Rectangle{
        id:backgroundWhite
        anchors.fill: parent
        radius:20
        color:PaletteMaster.darkGrayUI
    }
    Rectangle{
        id:secondbackgroundWhite
        color: PaletteMaster.darkGrayUI
        radius:20
        height: parent.height-10
        clip: true
        anchors{
            top:parent.top
            right: parent.right
            left:parent.left
        }
        ListView{
            id:listViewMain
            width: 460
            height: 250


            model: ProxyLibrary
            delegate: MiniDelegatesSearchBar{
                albumInfo: model.songAlbumPhoto
                textInfo: model.songName
            }

        }
    }


}
