#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager singleton;

    return singleton;
}

DatabaseManager::DatabaseManager( const QString& path ) :
    sqlDatabase( new QSqlDatabase( QSqlDatabase::addDatabase( "QSQLITE" ) ) ),
    albumDao( *sqlDatabase ),
    pictureDao( *sqlDatabase )
{
    sqlDatabase->setDatabaseName( path );
    sqlDatabase->open();

    albumDao.init();
}

DatabaseManager::~DatabaseManager() {
    sqlDatabase->close();

    delete sqlDatabase;
    sqlDatabase = NULL;
}
