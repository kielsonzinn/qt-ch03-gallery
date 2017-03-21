#include "albumlistwidget.h"
#include "ui_albumlistwidget.h"

#include <QInputDialog>

#include "albummodel.h"

AlbumListWidget::AlbumListWidget( QWidget* parent ) :
    QWidget( parent ),
    ui( new Ui::AlbumListWidget ),
    mAlbumModel( NULL )
{
    ui->setupUi( this );

    connect( ui->createAlbumButton, &QPushButton::clicked, this, &AlbumListWidget::createAlbum );
}

AlbumListWidget::~AlbumListWidget() {
    delete ui;
}

void AlbumListWidget::setModel( AlbumModel* model ) {
    mAlbumModel = model;

    ui->albumList->setModel(mAlbumModel);
}

void AlbumListWidget::setSelectionModel( QItemSelectionModel* selectionModel ) {
    ui->albumList->setSelectionModel( selectionModel );
}

void AlbumListWidget::createAlbum() {

    if ( !mAlbumModel ) {
        return;
    }

    bool isOkeey;

    QString albumName = QInputDialog::getText( this, "Criar novo album", "Informe um nome", QLineEdit::Normal, "Novo album", &isOkeey );

    if ( isOkeey && !albumName.isEmpty() ) {
        Album album( albumName );

        QModelIndex createdIndex = mAlbumModel->addAlbum( album );
        ui->albumList->setCurrentIndex( createdIndex );
    }

}
