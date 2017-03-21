#include "album.h"

Album::Album( const QString& name ) :
    idAlbum( -1 ),
    dsNome( name )
{

}

int Album::getIdAlbum() const {
    return idAlbum;
}

void Album::setIdAlbum( int value ) {
    idAlbum = value;
}

QString Album::getDsNome() const {
    return dsNome;
}

void Album::setDsNome( const QString& value ) {
    dsNome = value;
}
