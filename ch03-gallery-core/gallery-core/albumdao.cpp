#include "albumdao.h"

#include <QVariant>
#include <QSqlQuery>
#include <QStringList>
#include <QSqlDatabase>

#include "album.h"
#include "databasemanager.h"

AlbumDao::AlbumDao( QSqlDatabase& database ) :
    sqlDatabase( database )
{

}

void AlbumDao::init() const {

    if ( !sqlDatabase.tables().contains( "albums" ) ) {

        QSqlQuery query( sqlDatabase );
        query.exec( "CREATE TABLE albums ( id_album INTEGER PRIMARY KEY AUTOINCREMENT, ds_nome TEXT )" );

    }

}

void AlbumDao::addAlbum( Album& album ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "INSERT INTO albums ( ds_nome ) VALUES ( :dsNome )" );

    query.bindValue( ":dsNome", album.getDsNome() );

    query.exec();

    album.setIdAlbum( query.lastInsertId().toInt() );

}

void AlbumDao::updateAlbum( const Album& album ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "UPDATE albums SET ds_nome = :dsNome WHERE id_album = :idAlbum" );

    query.bindValue( ":dsNome", album.getDsNome() );
    query.bindValue( ":idAlbum", album.getIdAlbum() );

    query.exec();

}

void AlbumDao::removeAlbum( int id ) const {

    QSqlQuery query( sqlDatabase );
    query.prepare( "DELETE FROM albums WHERE id_album = :idAlbum" );

    query.bindValue( ":idAlbum", id );

    query.exec();

}

QVector<Album*> AlbumDao::albuns() const {

    QVector<Album*> list;

    QSqlQuery query( "SELECT * FROM albums", sqlDatabase );
    query.exec();

    while( query.next() ) {
        Album* album = new Album();
        album->setIdAlbum( query.value( "id_album" ).toInt() );
        album->setDsNome( query.value( "ds_nome" ).toString() );

        list.append( album );
    }

    return list;

}
