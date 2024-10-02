import QtQuick 2.15
import QtQuick.Controls.Basic
import com.library
import VaultTones01
Item {
    readonly property NotesMusicPlayer notesMusicController:  NotesMusicPlayer{}

    id:root
    property string text: "spuops"
    property string configUrl: ""
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

        Slider {
            id:slider
            anchors{
                verticalCenter: parent.verticalCenter
                left: playButton.right
                leftMargin: 10
                right: parent.right
                rightMargin: 25
            }
            // modificar: cambiar LibraryBackens por notesMusicController. config audio y detalles de duracion.
            from: 0
            to: LibraryBackends.musicplayer.sliderDuration
            value: LibraryBackends.musicplayer.sliderPosition
            onPressedChanged: LibraryBackends.musicplayer.pausedSlider(slider.value)
            // modificar
            handle.opacity: 0
        }
    }

}
