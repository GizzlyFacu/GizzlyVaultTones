#ifndef SAVEJSON_H
#define SAVEJSON_H

#include <QObject>
#include <QList>
#include "notesclass.h"
class saveJSON : public QObject
{
    Q_OBJECT
public:
    explicit saveJSON(QObject *parent = nullptr);
    void writeJsonToFile(QList<Notes*> notesList);


signals:
private:
    QList<Notes*> m_noteslist;
};

#endif // SAVEJSON_H
