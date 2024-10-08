#include "librarybackend.h"
#include <QDebug>
LibraryBackend::LibraryBackend(QObject *parent)
    : QAbstractListModel{parent}
{

    addSongs("NOMBRE EPICO", QUrl::fromLocalFile("C:/Users/usuario/Music/cumbion.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    addSongs("NOMBRE EPICO2", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"));

}

int LibraryBackend::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_dataList.length();
}

QVariant LibraryBackend::data(const QModelIndex &index, int role) const
{
    //si la info que me pide esta bn..
    if(index.isValid() && index.row()>=0 && index.row()<m_dataList.length() ){
        //pasarle la info
        Data* dataTemp=m_dataList[index.row()];
        switch ((Roles)role) {
        case SongNameRole:
            return dataTemp->songName;
            break;
        case SongFileRole:
            return dataTemp->songFile;
            break;
        case SongPhotoRole:
            return dataTemp->songPhoto;
            break;
        }
    }

    return {};
}

QHash<int, QByteArray> LibraryBackend::roleNames() const
{
    QHash<int,QByteArray> dataEntry;
    dataEntry[SongNameRole]="songName";
    dataEntry[SongFileRole]="songFile";
    dataEntry[SongPhotoRole]="songAlbumPhoto";
    return dataEntry;
}

void LibraryBackend::addSongs(QString SongName, QUrl SongFile, QUrl SongPhoto)
{
    //making a secure copy folder for Songfile and SongPhoto


    //actual add songs
    beginInsertRows(QModelIndex(),m_dataList.length(),m_dataList.length());

    Data* newSong=new Data;
    newSong->songName = SongName;
    newSong->songFile = SongFile;
    newSong->songPhoto = SongPhoto;
    m_dataList.append(newSong);

    endInsertRows();
}



void LibraryBackend::setSelected(int indets)
{
    actualIndex=indets;
    QList<Notes*> notesInfo=m_dataList.at(indets)->songNotes;
    m_notesmodel->updateModel(notesInfo);
    //--actualizando textplaylist

    m_selected_songName=m_dataList.at(indets)->songName;//Title
    emit selected_songNameChanged();

    m_musicplayer->configSong(m_dataList.at(indets)->songFile);//Music
    qDebug()<<"actualizando lista brrr"<<actualIndex;
}

void LibraryBackend::addsongNotes(QString NoteText, QString Type)
{
    //armar el Notes
    Notes* nota=new Notes;
    nota->note=NoteText;
    nota->type=Type;
    //aniadir Notes al Qlist
    m_dataList.at(actualIndex)->songNotes.append(nota);
    //actualizar la UI
    m_notesmodel->updateModel(m_dataList.at(actualIndex)->songNotes);
}

notesclass *LibraryBackend::notesmodel() const
{
    return m_notesmodel;
}

MusicPlayer *LibraryBackend::musicplayer() const
{
    return m_musicplayer;
}



QString LibraryBackend::selected_songName() const
{
    return m_selected_songName;
}
