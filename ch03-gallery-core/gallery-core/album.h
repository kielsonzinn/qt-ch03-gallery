#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Album {

public:
    explicit Album( const QString& name = "" );

    int getIdAlbum() const;
    void setIdAlbum( int value );

    QString getDsNome() const;
    void setDsNome( const QString& value );

private:
    int idAlbum;
    QString dsNome;

};

#endif // ALBUM_H
