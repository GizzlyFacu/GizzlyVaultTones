#ifndef LIBRARYBACKEND_H
#define LIBRARYBACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>
#include <QList>
#include "notesclass.h"

struct Data{
    QString songName = "default name";
    QUrl songFile;
    QUrl songPhoto;
};

class LibraryBackend : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(notesclass* notesmodel READ notesmodel CONSTANT)
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

signals:

public slots:
    void addSongs(QString SongName, QUrl SongFile, QUrl SongPhoto);
    void setSelected(int indets);
private:
    QList<Data*> m_dataList;

    notesclass *m_notesmodel = new notesclass(this);
};

#endif // LIBRARYBACKEND_H
