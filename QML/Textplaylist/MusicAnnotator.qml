import QtQuick 2.15
import com.library
Item {
    id:root
    width: parent.width
    height: 220
    clip:true


    ListView{
        id:listNotes
        model:LibraryBackends.notesmodel
        anchors.fill: parent
        delegate:Loader{
            id:loader
            source: {
                switch (model.typenote){
                case "text":
                    return delegates.delegateText;
                case "audio":
                    return delegates.delegateAudio;
                }
            }
            onLoaded: {
                loader.item.text = model.textnote
                loader.item.configSong()
                loader.item.widthX = listNotes.width
            }
        }
        footer: FooterItem{}
    }
    QtObject{
        id:delegates
        property string delegateText:"qrc:/textplaylist/DelegateText.qml"
        property string delegateAudio: "qrc:/textplaylist/DelegateAudio.qml"
    }
}
