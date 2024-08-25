#ifndef PROXYLIBRARY_H
#define PROXYLIBRARY_H

#include <QObject>
#include <QSortFilterProxyModel>
class ProxyLibrary : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit ProxyLibrary(QObject *parent = nullptr);

signals:
public slots:
    void getTextInput(const QString textInput);
    // QSortFilterProxyModel interface
protected:
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString m_textInput="NOMBRE EPICO";
};

#endif // PROXYLIBRARY_H
