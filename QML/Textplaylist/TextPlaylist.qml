import QtQuick 2.15
import com.library
Item {
    id:root
    width: 338
    height: 367

    Item{
        id:spacedRoot
        width: 291
        height: 220
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 13
        z:1

        Text{
            id:titleText
            width: parent.width
            text:"title"
            font{
                pixelSize: 20
                bold:true
            }
            horizontalAlignment: Text.AlignHCenter
            color:PaletteMaster.whiteText
            /*
            Rectangle{
            id:titleSpace
                anchors.fill: parent
                color:"white"
            }
            */
        }

        Rectangle{
            id:separator
            width: parent.width
            height: 1
            color:PaletteMaster.lightGrayText
            anchors.top: parent.top
            anchors.topMargin: 56-13
        }

        MusicAnnotator{
            id:annotator
            anchors.top: parent.top
            anchors.topMargin: 66-13

        }
    }

    MusicPlayerController{
        id:playerController
        anchors{
            bottom: parent.bottom
            bottomMargin: 12
        }

        z:1
    }

    Rectangle{
        id:background
        anchors.fill: parent
        color:PaletteMaster.darkGrayUI
        radius: 20
        z:0
    }


}
