#include "picturedao.h"

#include <QVariant>
#include <QSqlQuery>
#include <QStringList>
#include <QSqlDatabase>

#include "picture.h"

PictureDao::PictureDao(QSqlDatabase& database) : sqlDatabase( database ) {

}

void PictureDao::init() const {

    if ( !sqlDatabase.tables().contains( "pictures" ) ) {
        QSqlQuery query( sqlDatabase );
        query.exec( "CREATE TABLE pictures ( id_picture INTEGER PRIMARY KEY AUTOINCREMENT, id_album INTEGER, ds_url TEXT )");
    }

}

void PictureDao::addPictureInAlbum( int idAlbum, Picture& picture ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "INSERT INTO pictures ( id_album, ds_url ) VALUES ( :idAlbum, :dsUrl )" );

    query.bindValue( ":idAlbum", idAlbum );
    query.bindValue( ":dsUrl", picture.getUrlPicture() );

    query.exec();

    picture.setIdPicture( query.lastInsertId().toInt() );
    picture.setIdAlbum( idAlbum );

}

void PictureDao::removePicture( int id ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "DELETE FROM pictures WHERE id_picture = :idPicture" );

    query.bindValue( ":idPicture", id );

    query.exec();

}

void PictureDao::removePicturesForAlbum( int idAlbum ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "DELETE FROM pictures WHERE id_album = :idAlbum" );

    query.bindValue( ":idAlbum", idAlbum );

    query.exec();

}

QVector<Picture*> PictureDao::picturesForAlbum( int idAlbum ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "SELECT * FROM pictures WHERE album_id = :idAlbum");

    query.bindValue( ":idAlbum", idAlbum );

    query.exec();

    QVector<Picture*> list;

    while ( query.next() ) {
        Picture* picture = new Picture();
        picture->setIdPicture( query.value( "id_picture" ).toInt() );
        picture->setIdAlbum( query.value( "id_album" ).toInt() );
        picture->setUrlPicture( query.value( "ds_url" ).toString() );

        list.append( picture );
    }

    return list;

}
