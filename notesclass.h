#ifndef NOTESCLASS_H
#define NOTESCLASS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
struct Notes{
    QString note="default note";
    QString type="default type";
};

class notesclass : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit notesclass(QObject *parent = nullptr);

signals:

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    enum Roles{
        NoteRole=Qt::UserRole+1,
        TypeRole
    };
    void addNotes(QString Name, QString Type);
    void updateModel(QList<Notes*> List);
private:
    QList<Notes*> m_noteslist;
};

#endif // NOTESCLASS_H
