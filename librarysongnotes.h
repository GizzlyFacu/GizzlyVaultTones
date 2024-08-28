#ifndef LIBRARYSONGNOTES_H
#define LIBRARYSONGNOTES_H

#include <QObject>

class LibrarySongNotes : public QObject
{
    Q_OBJECT
public:
    explicit LibrarySongNotes(QObject *parent = nullptr);

signals:
};

#endif // LIBRARYSONGNOTES_H
