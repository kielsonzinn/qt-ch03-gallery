TEMPLATE = app

QT += qml quick sql svg

CONFIG += c++11

HEADERS += \
    pictureimageprovider.h

SOURCES += main.cpp \
    pictureimageprovider.cpp

RESOURCES += \
    gallery.qrc

contains(ANDROID_TARGET_ARCH,x86) {
    ANDROID_EXTRA_LIBS = \
        $$[QT_INSTALL_LIBS]/libQt5Sql.so
}

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
