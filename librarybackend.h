#ifndef LIBRARYBACKEND_H
#define LIBRARYBACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>
#include <QList>
#include "librarysongnotes.h"
//una parte del modelo se encarga de mostrar la data.
//otra de enviar las Song Notes.


struct Data{
    QString songName = "default name";
    QUrl songFile;
    QUrl songPhoto;
    QList<SongNote*> m_notesList;
};

class LibraryBackend : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit LibraryBackend(QObject *parent = nullptr);
    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    enum Roles{
        SongNameRole=Qt::UserRole+1,
        SongFileRole,
        SongPhotoRole
    };

signals:

public slots:
    void addSongs(QString SongName, QUrl SongFile, QUrl SongPhoto);
    void addSongNotes();
    void setSelected(int indets);
public:
    LibrarySongNotes* modelSongNote= new LibrarySongNotes;

private:
    QList<Data*> m_dataList;
    int actualIndets;
};

#endif // LIBRARYBACKEND_H
