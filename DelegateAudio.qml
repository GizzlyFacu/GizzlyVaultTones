import QtQuick 2.15
import com.library
Item {
    id:root
    property string text: "spuops"
    property int widthX:100
    height: 30+10

    Rectangle{
        id:background
        width: widthX
        height: 30
        anchors.bottom: parent.bottom

        color:Qt.darker(PaletteMaster.darkGrayUI)
        radius:20
        ImageButtons{
            property bool playPause:true
            id:playButton
            anchors{
                verticalCenter: parent.verticalCenter
                left:parent.left
                leftMargin: 5
            }

            source:playPause ? "qrc:/resources/assets/icons/play.svg":"qrc:/resources/assets/icons/pause.svg"
            color:PaletteMaster.whiteText
            iconWidth: 30
            iconHeight: 30
            onClickeds:playPause=!playPause
        }
    }

}
