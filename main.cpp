#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "librarybackend.h"
#include "proxylibrary.h"
#include "palettemaster.h"
#include "librarysongnotes.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    LibraryBackend* newLibrary = new LibraryBackend;
    ProxyLibrary* newProxyLibrary = new ProxyLibrary;
    newProxyLibrary->setSourceModel(newLibrary);

    qmlRegisterSingletonInstance("com.library",1,0,"LibraryBackends",newLibrary);
    qmlRegisterSingletonInstance("com.library",1,0,"ProxyLibrary",newProxyLibrary);
    PaletteMaster* newPalette = new PaletteMaster;
    qmlRegisterSingletonInstance("com.library",1,0,"PaletteMaster",newPalette);
    LibrarySongNotes* newSongNotes=new LibrarySongNotes;
    qmlRegisterSingletonInstance("com.library",1,0,"SongNotes",newSongNotes);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/VaultTones01/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
