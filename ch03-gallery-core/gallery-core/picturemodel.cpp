#include "picturemodel.h"

#include "albummodel.h"
#include "databasemanager.h"

PictureModel::PictureModel( const AlbumModel& albumModel, QObject* parent ) :
    QAbstractListModel( parent ),
    mDb( DatabaseManager::instance() ),
    mAlbumId( -1 )
{
    connect( &albumModel, &AlbumModel::rowsRemoved, this, &PictureModel::deletePicturesForAlbum );
}

QModelIndex PictureModel::addPicture( const Picture& picture ) {

    int rowIndex = rowCount();

    beginInsertRows( QModelIndex(), rowIndex, rowIndex );

    Picture* newPicture = new Picture( picture );

    mDb.pictureDao.addPictureInAlbum( picture.getIdAlbum(), *newPicture );
    mPictures.append( newPicture );

    endInsertRows();

    return index( rowIndex, 0 );

}

int PictureModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED( parent );

    return mPictures.size();
}

QVariant PictureModel::data( const QModelIndex& index, int role ) const {

    if ( !isIndexValid( index ) ) {
        return QVariant();
    }

    const Picture& picture = *mPictures.at( index.row() );

    switch ( role ) {
        case Qt::DisplayRole:
            return picture.getUrlPicture().fileName();
        case Roles::UrlRole:
            return picture.getUrlPicture();
        case Roles::FilePathRole:
            return picture.getUrlPicture().toLocalFile();
        default:
            return QVariant();
    }

}

bool PictureModel::removeRows( int row, int count, const QModelIndex& parent ) {

    if ( row < 0 || row >= rowCount() || count < 0 || ( row + count ) > rowCount() ) {
        return false;
    }

    beginRemoveRows( parent, row, row + count - 1 );

    int countLeft = count;

    while ( countLeft-- ) {
        const Picture& picture = *mPictures.at( row + countLeft );

        mDb.pictureDao.removePicture( picture.getIdPicture() );
    }

    mPictures.erase( mPictures.begin() + row, mPictures.begin() + row + count );

    endRemoveRows();

    return true;

}

void PictureModel::setAlbumId( int albumId ) {

    beginResetModel();
    mAlbumId = albumId;
    loadPictures( albumId );
    endResetModel();

}

void PictureModel::clearAlbum() {
    setAlbumId( -1 );
}

void PictureModel::deletePicturesForAlbum() {
    mDb.pictureDao.removePicturesForAlbum( mAlbumId );

    clearAlbum();
}

void PictureModel::loadPictures( int albumId ) {

    if ( albumId <= 0 ) {
        mPictures.clear();
    } else {
        mPictures = mDb.pictureDao.picturesForAlbum( albumId );
    }

}

bool PictureModel::isIndexValid( const QModelIndex& index ) const {
    if ( index.row() < 0 || index.row() >= rowCount() || !index.isValid() ) {
        return false;
    }

    return true;
}
