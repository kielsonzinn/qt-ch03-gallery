#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "albummodel.h"

MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayGallery() {

}

void MainWindow::displayPicture( const QModelIndex& index ) {

}
