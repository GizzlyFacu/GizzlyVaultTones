#include "proxylibrary.h"
#include "librarybackend.h"
#include <QDebug>
ProxyLibrary::ProxyLibrary(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

void ProxyLibrary::getTextInput(const QString textInput)
{
    m_textInput=textInput;

    invalidateFilter();

}

bool ProxyLibrary::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    QString filterData = sourceModel()->data(index,LibraryBackend::SongNameRole).toString();
    filterData=filterData.toLower();

    // Filtrar solo nombres que comienzan con "A" y tienen una longitud mayor a 3 caracteres
    return (filterData.contains(m_textInput,Qt::CaseSensitive));
}
