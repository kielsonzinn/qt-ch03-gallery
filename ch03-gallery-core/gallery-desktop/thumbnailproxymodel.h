#ifndef THUMBNAILPROXYMODEL_H
#define THUMBNAILPROXYMODEL_H

#include <QHash>
#include <QPixmap>
#include <QIdentityProxyModel>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel {

public:
    ThumbnailProxyModel( QObject* parent = NULL );

    QVariant data( const QModelIndex& index, int role ) const override;
    void setSourceModel( QAbstractItemModel* sourceModel ) override;
    PictureModel* pictureModel() const;

private:
    void generateThumbnails( const QModelIndex& startIndex, int count );
    void reloadThumbnails();

private:
    QHash<QString, QPixmap*> mThumbnails;

};

#endif // THUMBNAILPROXYMODEL_H
