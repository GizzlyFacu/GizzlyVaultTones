import QtQuick
import Qt5Compat.GraphicalEffects
import VaultTones01

Window {
    id:root
    width: 896
    height: 504
    visible: true
    color: "black"
    title: qsTr("Hello World")

    LibraryA{
        id: base
        anchors.centerIn: parent
    }
    DelegateAlbun{
        id:sas
        x:700
        y:50
    }

}
