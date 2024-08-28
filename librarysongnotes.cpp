#include "librarysongnotes.h"

LibrarySongNotes::LibrarySongNotes(QObject *parent)
    : QAbstractListModel{parent}
{

}

int LibrarySongNotes::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_notesList.length();
}

QVariant LibrarySongNotes::data(const QModelIndex &index, int role) const
{
    //confirma si existe ese lugar, si existe devuelve la info dependiendo del rol.
    if (index.isValid() && index.row()>=0 && index.row()<m_notesList.length()){
        SongNote* songNoteResult=m_notesList[index.row()];
        switch ((Roles)role) {
        case NoteTextRole:
            return songNoteResult->note;
        case NoteTypeRole:
            return songNoteResult->type;
            break;
        }
    }
    return{};//no returna nadas alv.
}

QHash<int, QByteArray> LibrarySongNotes::roleNames() const
{
    QHash<int,QByteArray> result;
    result[NoteTextRole]="text";
    result[NoteTypeRole]="type";
    return result;
}

void LibrarySongNotes::showActualQlist(QList<SongNote*> List)
{
    beginInsertRows(QModelIndex(),m_notesList.length(),m_notesList.length());
    m_notesList=List;
    endInsertRows();
}




