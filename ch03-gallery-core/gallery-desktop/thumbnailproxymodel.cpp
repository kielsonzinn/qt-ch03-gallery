#include "thumbnailproxymodel.h"

#include "picturemodel.h"

const unsigned int THUMBNAIL_SIZE = 350;

void ThumbnailProxyModel::generateThumbnails( const QModelIndex& startIndex, int count ) {

    if ( !startIndex.isValid() ) {
        return;
    }

    const QAbstractItemModel* model = startIndex.model();
    int lastIndex = startIndex.row() + count;

    for ( int row = startIndex.row(); row < lastIndex; row++ ) {
        QString filepath = model->data( model->index( row, 0 ), PictureModel::Roles::FilePathRole ).toString();

        QPixmap pixmap( filepath );
        auto thumbnail = new QPixmap( pixmap.scaled( THUMBNAIL_SIZE, THUMBNAIL_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation ) );
        mThumbnails.insert( filepath, thumbnail );
    }

}

void ThumbnailProxyModel::reloadThumbnails() {
    qDeleteAll( mThumbnails );
    mThumbnails.clear();

    generateThumbnails( index( 0, 0 ), rowCount() );
}

void ThumbnailProxyModel::setSourceModel( QAbstractItemModel* sourceModel ) {

    QIdentityProxyModel::setSourceModel( sourceModel );

    if ( !sourceModel ) {
        return;
    }

    connect( sourceModel, &QAbstractItemModel::modelReset, [this] {
        reloadThumbnails();
    });

    connect( sourceModel, &QAbstractItemModel::rowsInserted, [this]( const QModelIndex& parent, int first, int last ) {
        Q_UNUSED( parent );
        generateThumbnails( index( first, 0 ), last - first + 1 );
    });

}

QVariant ThumbnailProxyModel::data( const QModelIndex& index, int role ) const {

    if ( role != Qt::DecorationRole ) {
        return QIdentityProxyModel::data( index, role );
    }

    QString filepath = sourceModel()->data( index, PictureModel::Roles::FilePathRole ).toString();

    return *mThumbnails[ filepath ];

}

PictureModel* ThumbnailProxyModel::pictureModel() const {
    return static_cast<PictureModel*>( sourceModel() );
}
