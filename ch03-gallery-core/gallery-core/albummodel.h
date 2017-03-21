#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QHash>
#include <QVector>
#include <QAbstractListModel>

#include "album.h"
#include "databasemanager.h"
#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT AlbumModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    AlbumModel( QObject* parent = NULL );

    QModelIndex addAlbum( const Album& album );
    int rowCount( const QModelIndex& parent = QModelIndex() ) const override;
    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;
    bool setData( const QModelIndex& index, const QVariant& value, int role ) override;
    bool removeRows( int row, int count, const QModelIndex& parent ) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid( const QModelIndex& index ) const;

private:
    DatabaseManager& mDb;
    QVector<Album*> mAlbuns;

};

#endif // ALBUMMODEL_H
