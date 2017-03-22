#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

class GalleryWidget;
class PictureWidget;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow( QWidget* parent = NULL );
    ~MainWindow();

public slots:
    void displayGallery();
    void displayPicture( const QModelIndex& index );

private:
    Ui::MainWindow *ui;
    GalleryWidget* mGalleryWidget;
    PictureWidget* mPictureWidget;
    QStackedWidget* mStackedWidget;

};

#endif // MAINWINDOW_H
