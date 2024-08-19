import QtQuick
import Qt5Compat.GraphicalEffects


Item {
    id:root
    property alias source: icon.source
    property alias color: colorOverlay.color
    property alias iconWidth:root.width
    property alias iconHeight:root.height

    Image{
        id:icon
        anchors.fill: parent
        ColorOverlay{
            id:colorOverlay
            anchors.fill: parent
            source:icon
            antialiasing: true
        }
    }
}
