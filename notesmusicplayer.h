#ifndef NOTESMUSICPLAYER_H
#define NOTESMUSICPLAYER_H

#include <QObject>
#include "musicplayer.h"
#include <QQmlEngine>

class NotesMusicPlayer : public MusicPlayer
{
    Q_OBJECT
    QML_ELEMENT

public:
    void pepe();
signals:
};

#endif // NOTESMUSICPLAYER_H
