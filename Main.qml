import QtQuick
import Qt5Compat.GraphicalEffects
import VaultTones01
import com.library

Window {
    id:root
    width: 896
    height: 504
    visible: true
    color: PaletteMaster.lightGrayUI
    title: qsTr("Hello World")

    LibraryA{
        id: base
        x:28
        y:101
    }

    TextPlaylist{
        id:textplaylist
        x:896-338-31
        y:101
    }

}
