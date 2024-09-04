import QtQuick 2.15
import com.library
Item {
    id:root
    property string text: "spuops"
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
        text:"Text..."
        z:1
    }
}
