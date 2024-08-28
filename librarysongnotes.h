#ifndef LIBRARYSONGNOTES_H
#define LIBRARYSONGNOTES_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
struct SongNote{
    QString note;
    QString type;
};

class LibrarySongNotes : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LibrarySongNotes(QObject *parent = nullptr);

signals:



    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    enum Roles{
        NoteTextRole=Qt::UserRole+1,
        NoteTypeRole
    };
    void addElements(QString pepe,QString pepa);
private:
    QList<SongNote*> m_notesList;
};

#endif // LIBRARYSONGNOTES_H
