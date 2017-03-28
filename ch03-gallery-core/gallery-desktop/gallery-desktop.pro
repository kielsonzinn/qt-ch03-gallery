QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gallery-desktop
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    albumlistwidget.cpp \
    thumbnailproxymodel.cpp \
    albumwidget.cpp \
    picturedelegate.cpp \
    picturewidget.cpp \
    gallerywidget.cpp

HEADERS  += mainwindow.h \
    albumlistwidget.h \
    thumbnailproxymodel.h \
    albumwidget.h \
    picturedelegate.h \
    picturewidget.h \
    gallerywidget.h

FORMS    += mainwindow.ui \
    albumlistwidget.ui \
    albumwidget.ui \
    picturewidget.ui \
    gallerywidget.ui

RESOURCES += \
    resource.qrc

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}

CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

#{ gallery-core

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gallery-core/$$DESTDIR -lgallery-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gallery-core/$$DESTDIR -lgallery-core
else:unix: LIBS += -L$$PWD/../gallery-core/$$DESTDIR -lgallery-core

INCLUDEPATH += $$PWD/../gallery-core

#} gallery-core
