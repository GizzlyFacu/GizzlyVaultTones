#include "librarybackend.h"
#include <QDebug>
LibraryBackend::LibraryBackend(QObject *parent)
    : QAbstractListModel{parent}
{
    addSongs("NOMBRE EPICO", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    addSongs("NOMBRE EPICO2", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));
    addSongs("NOMBRE EPICO3", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    addSongs("NOMBRE EPICO4", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    addSongs("NOMBRE EPICO5", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    addSongs("NOMBRE EPICO6", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));
    addSongs("NOMBRE EPICO7", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));
    addSongs("NOMBRE EPICO8", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));
    addSongs("NOMBRE EPICO9", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));
    addSongs("NOMBRE EPICO10", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/si.png"));

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

    QList<Notes*>sas;
    Notes* cac=new Notes;
    cac->note="biribang";
    cac->type="typebang";
    sas.append(cac);
    if(indets==2){
        qDebug()<<"actualizando lista brrr";

        m_notesmodel->updateModel(sas);
    }
    qDebug()<<indets;
}

notesclass *LibraryBackend::notesmodel() const
{
    return m_notesmodel;
}
