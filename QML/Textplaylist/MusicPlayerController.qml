import QtQuick 2.15
import QtQuick.Controls.Basic
import "../Utilities"
import com.library
Item {

    id:root
    height: 53
    width: parent.width

    Rectangle{
        id:button
        width: 40
        height: 40
        radius:40
        color:PaletteMaster.whiteText
        anchors{
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }
        IconButtonsFinal{
            property bool playPause:true
            id:playButton
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            source: LibraryBackends.musicplayer.playPause ? "qrc:/resources/assets/icons/play.svg":"qrc:/resources/assets/icons/pause.svg"
            color:PaletteMaster.darkGrayUI
            iconHeight: 24
            iconWidth: 24
            z:1
            onClickeds:LibraryBackends.musicplayer.playMusic()

        }
    }

    Slider {
        id:slider
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: -(slider.height/2)
        }
        from: 0
        to: LibraryBackends.musicplayer.sliderDuration
        value: LibraryBackends.musicplayer.sliderPosition
        onPressedChanged: LibraryBackends.musicplayer.pausedSlider(slider.value)
    }

    Text{
        id:musicPositionText
        anchors.verticalCenter: slider.verticalCenter
        anchors.right: slider.left
        x:50
        text:LibraryBackends.musicplayer.sliderPosition
        color:"white"
    }
    Text{
        id:musicDurationText
        anchors.verticalCenter: slider.verticalCenter
        anchors.left:slider.right
        text:LibraryBackends.musicplayer.sliderDuration
        color:"white"
    }
}
