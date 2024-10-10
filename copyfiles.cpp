#include "copyfiles.h"
//files managing
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>
CopyFiles::CopyFiles() {}

void CopyFiles::creatingFolder()
{
    //creating a secure copy folder for SongFile and SongPhoto
    QString FolderName=SongName.split(".")[0];
    QString DocumentsUrl=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString SongFolderUrl=(DocumentsUrl+"/Vaultones"+"/"+FolderName);
    QDir SecureFolder;
    SecureFolder.mkpath(SongFolderUrl);
}

bool CopyFiles::copiarArchivo(const QString folderName,const QString &origen, const QString &destino)
{
    QFile archivoOrigen(origen);
    QFile archivoDestino(destino);

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
