QT       += sql

QT       -= gui

TARGET = gallery-core
TEMPLATE = lib

DEFINES += GALLERYCORE_LIBRARY

SOURCES += album.cpp \
    picture.cpp \
    databasemanager.cpp \
    albumdao.cpp \
    picturedao.cpp \
    albummodel.cpp \
    picturemodel.cpp

HEADERS += gallery-core_global.h \
    album.h \
    picture.h \
    databasemanager.h \
    albumdao.h \
    picturedao.h \
    albummodel.h \
    picturemodel.h

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
