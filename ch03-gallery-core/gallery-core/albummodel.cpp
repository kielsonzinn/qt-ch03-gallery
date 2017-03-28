#include "albummodel.h"

AlbumModel::AlbumModel( QObject* parent ) :
    QAbstractListModel( parent ),
    mDb( DatabaseManager::instance() ),
    mAlbuns( mDb.albumDao.albuns() )
{

}

int AlbumModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent );

    return mAlbuns.size();
}

QVariant AlbumModel::data( const QModelIndex& index, int role ) const {

    if ( !isIndexValid( index ) ) {
        return QVariant();
    }

    const Album& album = *mAlbuns.at( index.row() );

    switch ( role ) {
        case Roles::IdRole:
            return album.getIdAlbum();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return album.getDsNome();

        default:
            return QVariant();
    }

}

QHash<int, QByteArray> AlbumModel::roleNames() const {

    QHash<int, QByteArray> roles;

    roles[Roles::IdRole] = "idAlbum";
    roles[Roles::NameRole] = "dsNome";

    return roles;

}

bool AlbumModel::isIndexValid( const QModelIndex& index ) const {
    if ( index.row() < 0 || index.row() >= rowCount() || !index.isValid() ) {
        return false;
    }

    return true;
}

QModelIndex AlbumModel::addAlbum( const Album& album ) {

    int rowIndex = rowCount();

    beginInsertRows( QModelIndex(), rowIndex, rowIndex );

    Album* newAlbum = new Album( album );

    mDb.albumDao.addAlbum( *newAlbum );
    mAlbuns.append( newAlbum );

    endInsertRows();

    return index( rowIndex, 0 );

}

void AlbumModel::addAlbumFromName( const QString& name ) {
    addAlbum( Album( name ) );
}

bool AlbumModel::setData( const QModelIndex& index, const QVariant& value, int role ) {

    if ( !isIndexValid( index ) || role != Roles::NameRole) {
        return false;
    }

    Album& album = *mAlbuns.at( index.row() );
    album.setDsNome( value.toString() );

    mDb.albumDao.updateAlbum( album );

    emit dataChanged( index, index );

    return true;

}

bool AlbumModel::removeRows( int row, int count, const QModelIndex& parent ) {

    if ( row < 0 || row >= rowCount() || count < 0 || ( row + count ) > rowCount() ) {
        return false;
    }

    beginRemoveRows( parent, row, row + count - 1 );

    int countLeft = count;

    while ( countLeft-- ) {
        const Album& album = *mAlbuns.at( row + countLeft );

        mDb.albumDao.removeAlbum( album.getIdAlbum() );
    }

    mAlbuns.erase( mAlbuns.begin() + row, mAlbuns.begin() + row + count );

    endRemoveRows();

    return true;

}
