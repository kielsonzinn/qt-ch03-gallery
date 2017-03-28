#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <QVector>
#include <QAbstractListModel>

#include "picture.h"
#include "gallery-core_global.h"

class Album;
class AlbumModel;
class DatabaseManager;

class GALLERYCORESHARED_EXPORT PictureModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        UrlRole = Qt::UserRole + 1,
        FilePathRole
    };

    PictureModel( const AlbumModel& albumModel, QObject* parent = NULL );

    QModelIndex addPicture( const Picture& picture );
    int rowCount( const QModelIndex& parent = QModelIndex() ) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool removeRows( int row, int count, const QModelIndex& parent ) override;
    Q_INVOKABLE void setAlbumId( int albumId );
    void clearAlbum();

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures( int albumId );
    bool isIndexValid( const QModelIndex& index ) const;

private:
    DatabaseManager& mDb;
    int mAlbumId;
    QVector<Picture*> mPictures;

};

#endif // PICTUREMODEL_H
