#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <QVector>

class Picture;
class QSqlDatabase;

class PictureDao {

public:
    explicit PictureDao( QSqlDatabase& database );
    void init() const;

    void addPictureInAlbum( int idAlbum, Picture& picture ) const;
    void removePicture( int id ) const;
    void removePicturesForAlbum( int idAlbum ) const;
    QVector<Picture*> picturesForAlbum( int albumId ) const;

private:
    QSqlDatabase& sqlDatabase;

};

#endif // PICTUREDAO_H
