#include "picturewidget.h"
#include "ui_picturewidget.h"

PictureWidget::PictureWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PictureWidget)
{
    ui->setupUi(this);
}

PictureWidget::~PictureWidget()
{
    delete ui;
}

void PictureWidget::setModel( ThumbnailProxyModel* model ) {
    //TODO implementar
}

void PictureWidget::setSelectionModel( QItemSelectionModel* selectionModel ) {
    //TODO implementar
}

void PictureWidget::resizeEvent( QResizeEvent* event ) {
    QWidget::resizeEvent( event );

    updatePicturePixmap();
}

void PictureWidget::deletePicture() {
    //TODO implementar
}

void PictureWidget::loadPicture( const QItemSelection& selected ) {
    //TODO implementar
}

void PictureWidget::updatePicturePixmap() {
    if ( mPixmap.isNull() ) {
        return;
    }

    ui->pictureLabel->setPixmap( mPixmap.scaled( ui->pictureLabel->size(), Qt::KeepAspectRatio ) );
}
