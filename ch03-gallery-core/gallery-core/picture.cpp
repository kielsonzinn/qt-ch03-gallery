#include "picture.h"

Picture::Picture( const QString& filePath ) :
    Picture( QUrl::fromLocalFile( filePath ) )
{

}

Picture::Picture( const QUrl& fileUrl ) :
    idPicture( -1 ),
    idAlbum( -1 ),
    urlPicture( fileUrl )
{

}

int Picture::getIdPicture() const {
    return idPicture;
}

void Picture::setIdPicture( int value ) {
    idPicture = value;
}

int Picture::getIdAlbum() const {
    return idAlbum;
}

void Picture::setIdAlbum( int value ) {
    idAlbum = value;
}

QUrl Picture::getUrlPicture() const {
    return urlPicture;
}

void Picture::setUrlPicture( const QUrl& value ) {
    urlPicture = value;
}
