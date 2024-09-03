import QtQuick
import VaultTones01
import com.library

Item {
    property alias albumInfo:delegateImage.source
    property alias textInfo:delegateText.text

    id:root
    width:400
    height: 50
    anchors.horizontalCenter: if(parent){return parent.horizontalCenter}
    Rectangle{
        id:spacedFill
        anchors.fill: parent
        color:PaletteMaster.darkGrayUI
    }


    Item{
        id:background
        width: 400
        height: 45
        anchors.bottom: parent.bottom
        Image{
            id:delegateImage
            height: 40
            width: 40
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
        }
        Text{
            id:delegateText
            width: parent.width
            anchors{
                top:parent.top
                left: delegateImage.right
                leftMargin: 10
            }

            color: PaletteMaster.whiteText
            font{
                pixelSize: 14
            }
        }
    }
}
