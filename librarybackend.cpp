#include "librarybackend.h"
#include <QDebug>
//files managing
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

LibraryBackend::LibraryBackend(QObject *parent)
    : QAbstractListModel{parent}
{
    //addSongs("cumbion.mp3", QUrl::fromLocalFile("C:/Users/usuario/Music/cumbion.mp3"),QUrl::fromLocalFile("C:/Users/usuario/Pictures/yo.png"));
    //addSongs("InitGang.mp3", QUrl::fromLocalFile("C:/Users/usuario/Music/InitGang.mp3"));
    autoSearch();
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
    //creating a secure copy folder for SongFile and SongPhoto
    QString FolderName=SongName.split(".")[0];
    QString DocumentsUrl=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString SongFolderUrl=(DocumentsUrl+"/Vaultones"+"/"+FolderName);
    QDir SecureFolder;
    SecureFolder.mkpath(SongFolderUrl);

    //moving songs to that folder
    copiarArchivo(SongFile.toString().remove("file:///"),(DocumentsUrl+"/Vaultones"+"/"+FolderName+"/"+SongName));

    //actual add songs
    beginInsertRows(QModelIndex(),m_dataList.length(),m_dataList.length());

    Data* newSong=new Data;
    newSong->songName = SongName;
    newSong->songFile = SongFile;
    newSong->songPhoto = SongPhoto;
    m_dataList.append(newSong);

    endInsertRows();
}

void LibraryBackend::deleteSongs(int Index)
{
    beginRemoveRows(QModelIndex(),Index,Index);

    m_dataList.removeAt(Index);
    endRemoveRows();
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

void LibraryBackend::autoSearch()
{
    //autobusca canciones dentro de las carpetas que NO esten en Notas
    //estas siempre van a ser los temas principales.
    QString DocumentsUrl=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString SongFolderUrl=(DocumentsUrl+"/Vaultones");
    QDir tracks(SongFolderUrl);

    //colocando filtros a la carpeta
    tracks.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::AllDirs);
    QStringList namefilters;
    namefilters<<"*.mp3";// << es lo mismo que .append()
    tracks.setNameFilters(namefilters);

    //busqueda
    QFileInfoList fileList = tracks.entryInfoList();  // Obtener la lista de archivos
    for (const QFileInfo &fileInfo : fileList) {
        if (fileInfo.isDir() && fileInfo.fileName()!="Notes") {
            // Si es un directorio, y es distinto a Notes, podemos buscar recursivamente dentro
            QDir subDir(fileInfo.filePath());
            QFileInfoList subFileList = subDir.entryInfoList(QDir::Files);
            for (const QFileInfo &subFileInfo : subFileList) {
                //qDebug() << "Archivo en subdirectorio:" << subFileInfo.fileName();
                addSongs(subFileInfo.fileName(),subFileInfo.filePath());
            }
        } else {
            qDebug() << "Archivo en el directorio principal:" << fileInfo.fileName();
        }
    }

}

bool LibraryBackend::copiarArchivo(const QString &origen, const QString &destino)
{
    QFile archivoOrigen(origen);
    QFile archivoDestino(destino);
    //qDebug()<<"origen: "<<origen;
    //qDebug()<<"destino: "<<destino;
    // Verificamos si el archivo de origen existe
    if (!archivoOrigen.exists()) {
        qDebug() << "El archivo de origen no existe:" << origen;
        return false;
    }

    // Intentamos copiar el archivo
    if (archivoOrigen.copy(destino)) {
        qDebug() << "Archivo copiado exitosamente de" << origen << "a" << destino;
        return true;
    } else {
        qDebug() << "Error al copiar el archivo:" << archivoOrigen.errorString();
        return false;
    }
}

void LibraryBackend::addsongNotes(QString NoteText, QString Type)
{
    if(Type=="audio"){
        qDebug()<<"audio";
    }else{
        qDebug()<<"texto";
    }

    //armar el Notes
    Notes* nota=new Notes;
    nota->note=NoteText;
    nota->type=Type;
    //aniadir Notes al Qlist
    m_dataList.at(actualIndex)->songNotes.append(nota);
    //actualizar la UI
    m_notesmodel->updateModel(m_dataList.at(actualIndex)->songNotes);
}

void LibraryBackend::deleteSongNotes(int Index)
{
    m_dataList.at(actualIndex)->songNotes.removeAt(Index);
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
