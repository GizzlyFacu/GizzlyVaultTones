import QtQuick
import Qt5Compat.GraphicalEffects

Item {
    id:root
    property alias source: icon.source
    property alias color: colorOverlay.color
    property alias iconWidth:root.width
    property alias iconHeight:root.height
    signal clickeds()

    Image{
        id:icon
        anchors.fill: parent
        ColorOverlay{
            id:colorOverlay
            anchors.fill: parent
            source:icon
            antialiasing: true
            smooth: true
        }
        fillMode: Image.PreserveAspectFit

    }
    MouseArea{
        id:clicknBeat
        anchors.fill: parent
        onClicked: root.clickeds()
    }
}
