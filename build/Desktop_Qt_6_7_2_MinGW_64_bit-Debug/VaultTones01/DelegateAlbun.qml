import QtQuick
import Qt5Compat.GraphicalEffects
Item {
    readonly property Pallete paletteMaster: Pallete{}
    property alias textInfo: delegateText.text
    property alias albumSource:albumImage.source
    id:root
    width: 100
    height: 143

    Item{
        //roundedImage: la verdadera imagen es OpacityMask, los otros dos son mascaras
        id:itemAlbum
        width: 100
        height: itemAlbum.width
        Item{
            id:metaMask
            visible:false
            width: 100
            height: 100
            Rectangle{
                id:basedMask
                width: parent.width
                height: parent.height
                radius:10
                color: "black"
            }
        }

        Image {
                id: albumImage
                visible:false
                anchors.centerIn: parent
                width: itemAlbum.width
                height: itemAlbum.width
            }

        OpacityMask {
                width: itemAlbum.width
                height: itemAlbum.width
                source: albumImage
                maskSource: metaMask
            }
    }


    Text {
        id: delegateText
        font.pixelSize: 12

        width: itemAlbum.width
        height: 45

        elide: Text.ElideRight
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere

        horizontalAlignment: Text.AlignHCenter
        anchors{
            top: itemAlbum.bottom
            topMargin: 5
            horizontalCenter: itemAlbum.horizontalCenter
        }
    }

}
