#ifndef PICTURE_H
#define PICTURE_H

#include <QUrl>
#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Picture {

public:
    Picture( const QString& filePath = "" );
    Picture( const QUrl& fileUrl );

    int getIdPicture() const;
    void setIdPicture( int value );

    int getIdAlbum() const;
    void setIdAlbum( int value );

    QUrl getUrlPicture() const;
    void setUrlPicture( const QUrl& value );

private:
    int idPicture;
    int idAlbum;
    QUrl urlPicture;

};

#endif // PICTURE_H
