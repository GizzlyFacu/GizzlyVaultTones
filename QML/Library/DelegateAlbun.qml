import QtQuick
import Qt5Compat.GraphicalEffects
import VaultTones01
import com.library
import QtQuick.Controls.Basic

Item {

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
        clip:true
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
        Item{
            property color selectedColor: "gray"
            id:selectedEffect
            anchors.fill: parent
            Rectangle{
                visible: if(epicMouseArea.containsMouse){
                             return 1;
                         }else{return 0;}

                width: parent.width
                height: parent.width
                color: if(epicMouseArea.containsPress){
                           return Qt.darker(selectedEffect.selectedColor)
                       }else{return Qt.lighter(selectedEffect.selectedColor)}

                opacity: 0.5
                radius: 10
            }
            MouseArea{
                id:epicMouseArea
                hoverEnabled: true
                anchors.fill: parent
                //onClicked: LibraryBackends.setSelected(index)
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: (mouse)=> {
                               if (mouse.button === Qt.RightButton)
                               menu.open();
                               else
                               LibraryBackends.setSelected(index);

                           }
            }
        }
    }

    Menu {
        id: menu
        y: albumImage.y+10
        x:albumImage.x+10
        width: 50

        MenuItem {
            text: "Delete"
            onClicked: LibraryBackends.deleteSongs(index);
        }
    }

    Text {
        id: delegateText
        font.pixelSize: 12
        color:PaletteMaster.lightGrayText
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
