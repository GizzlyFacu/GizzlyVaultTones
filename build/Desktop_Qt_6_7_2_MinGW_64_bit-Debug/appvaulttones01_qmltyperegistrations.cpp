/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <librarybackend.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_VaultTones01()
{
    qmlRegisterTypesAndRevisions<LibraryBackend>("VaultTones01", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("VaultTones01", 1);
    qmlRegisterModule("VaultTones01", 1, 0);
}

static const QQmlModuleRegistration vaultTones01Registration("VaultTones01", qml_register_types_VaultTones01);
