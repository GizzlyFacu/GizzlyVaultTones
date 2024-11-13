#include "savejson.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
saveJSON::saveJSON(QObject *parent)
    : QObject{parent}
{}

//tomar la informacion de los strucs y guardarlos

void saveJSON::writeJsonToFile(QList<Notes*> notesList)
{
    QJsonObject json_obj;
    QJsonObject json_subobj;

    if(notesList.size()>0){
        m_noteslist=notesList;
        for (auto note :m_noteslist){
            int contador=0;

            json_subobj["text"]=note->note;
            json_subobj["type"]=note->type;
            json_obj[QString::number(contador)]=json_subobj;
            contador++;
        }
    }

    QJsonDocument json_doc(json_obj);

    QFile json_file("notes_saves.json");
    if (json_file.open(QIODevice::WriteOnly)) {
        json_file.write(json_doc.toJson());
        json_file.close();
    } else {
        qDebug() << "error launching the .json file";
    }


}
