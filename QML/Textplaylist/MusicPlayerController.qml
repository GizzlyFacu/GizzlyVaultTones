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

            source: MusicPlayer.playPause ? "qrc:/resources/assets/icons/play.svg":"qrc:/resources/assets/icons/pause.svg"
            color:PaletteMaster.darkGrayUI
            iconHeight: 24
            iconWidth: 24
            z:1
            onClickeds:MusicPlayer.playMusic()

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
        to: MusicPlayer.sliderDuration
        value: MusicPlayer.sliderPosition
        onPressedChanged: MusicPlayer.pausedSlider(slider.value)
    }

    Text{
        id:musiPositionText
        anchors.verticalCenter: slider.verticalCenter
        anchors.right: slider.left
        x:50
        text:MusicPlayer.sliderPosition
        color:"white"
    }
    Text{
        id:musicDurationText
        anchors.verticalCenter: slider.verticalCenter
        anchors.left:slider.right
        text:MusicPlayer.sliderDuration
        color:"white"
    }
}
