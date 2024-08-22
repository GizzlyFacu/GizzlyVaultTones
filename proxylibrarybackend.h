#ifndef PROXYLIBRARYBACKEND_H
#define PROXYLIBRARYBACKEND_H

#include <QObject>

class proxylibrarybackend : public QObject
{
    Q_OBJECT
public:
    explicit proxylibrarybackend(QObject *parent = nullptr);

signals:
};

#endif // PROXYLIBRARYBACKEND_H
