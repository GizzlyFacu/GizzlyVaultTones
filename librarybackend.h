#ifndef LIBRARYBACKEND_H
#define LIBRARYBACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>
#include <QList>
#include "notesclass.h"
#include "musicplayer.h"

struct Data{
    QString songName = "default name";
    QUrl songFile;
    QUrl songPhoto;
    QList<Notes*> songNotes;//esto pertenece al otro modelo.
};

class LibraryBackend : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(notesclass* notesmodel READ notesmodel CONSTANT)
    Q_PROPERTY(MusicPlayer* musicplayer READ musicplayer CONSTANT)
    Q_PROPERTY(QString selected_songName READ selected_songName NOTIFY selected_songNameChanged FINAL)


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

    notesclass *notesmodel() const;

    MusicPlayer *musicplayer() const;



    QString selected_songName() const;

signals:

    void selected_songNameChanged();

public slots:
    void addSongs(QString SongName, QUrl SongFile, QUrl SongPhoto=QUrl::fromLocalFile(":/images/assets/images/default_image.jpg"));
    void addsongNotes(QString NoteText, QString Type);
    void setSelected(int indets);
private:
    QList<Data*> m_dataList;
    notesclass *m_notesmodel = new notesclass(this);
    int actualIndex;
    MusicPlayer *m_musicplayer = new MusicPlayer(this);

    QString m_selected_songName;

    bool copiarArchivo(const QString &origen, const QString &destino);
};

#endif // LIBRARYBACKEND_H
