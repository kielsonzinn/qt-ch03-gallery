#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "albumdao.h"
#include "picturedao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager {

public:
    static void debugQuery( const QSqlQuery& query );
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager( const QString& path = DATABASE_FILENAME );
    DatabaseManager& operator=( const DatabaseManager& rhs );

private:
    QSqlDatabase* sqlDatabase;

public:
    const AlbumDao albumDao;
    const PictureDao pictureDao;

};

#endif // DATABASEMANAGER_H
