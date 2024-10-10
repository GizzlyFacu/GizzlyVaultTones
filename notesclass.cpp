#include "notesclass.h"

notesclass::notesclass(QObject *parent)
    : QAbstractListModel{parent}
{
    addNotes("text","uno dos tres");
    addNotes("audio","file:///C:/Users/usuario/Music/despiertame.mp3");
    addNotes("audio","file:///C:/Users/usuario/Music/despiertame2.mp3");
    addNotes("text","queso siu pap");
    addNotes("audio","file:///C:/Users/usuario/Music/night1.mp3");

}

int notesclass::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_noteslist.length();
}

QVariant notesclass::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_noteslist.length()){
        Notes* notesResult=m_noteslist[index.row()];
        switch ((Roles)role) {
        case NoteRole:
            return notesResult->note;
        case TypeRole:
            return notesResult->type;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> notesclass::roleNames() const
{
    QHash<int,QByteArray> result;
    result[NoteRole]="textnote";
    result[TypeRole]="typenote";
    return result;
}

void notesclass::addNotes(QString Type,QString Name )
{
    //copiando archivos
    if(Type=="audio"){

    }else{

    }
    beginInsertRows(QModelIndex(),m_noteslist.length(),m_noteslist.length());
    Notes* data=new Notes;
    data->note=Name;
    data->type=Type;
    m_noteslist.append(data);
    endInsertRows();
}

void notesclass::updateModel(QList<Notes*> List)
{
    beginResetModel();
    m_noteslist=List;
    endResetModel();
}


