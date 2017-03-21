#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <QVector>
#include <memory.h>

class Album;
class QSqlDatabase;

class AlbumDao {

public:
    AlbumDao( QSqlDatabase& database );
    void init() const;

    void addAlbum( Album& album ) const;
    void updateAlbum( const Album& album ) const;
    void removeAlbum( int id ) const;
    QVector<Album*> albuns() const;

private:
    QSqlDatabase& sqlDatabase;

};

#endif // ALBUMDAO_H
