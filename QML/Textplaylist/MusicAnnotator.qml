import QtQuick 2.15
import com.library
Item {
    id:root
    width: parent.width
    height: 220

    ListModel{
        id:modelgang
        ListElement{
            name:"sas"
        }
        ListElement{
            name:"ses"
        }
        ListElement{
            name:"sis"
        }
    }

    ListView{
        id:cac
        model:NotesClassDemo
        anchors.fill: parent
        delegate:Rectangle{
            width: 100
            height: 100
            color:"black"
            Text{
                anchors.centerIn: parent
                text: model.textnote;
                color:"white"
            }
        }
    }
}
