#ifndef COPYFILES_H
#define COPYFILES_H
#include <QObject>
class CopyFiles
{
public:
    CopyFiles();

    void creatingFolder();
    bool copiarArchivo(const QString folderName, const QString &origen, const QString &destino);

};

#endif // COPYFILES_H
