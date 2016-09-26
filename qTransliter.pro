#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T14:10:21
#
#-------------------------------------------------

QT       -= gui

TARGET = qTransliter
TEMPLATE = lib

DEFINES += QTRANSLITER_LIBRARY

SOURCES += QTransliter.cpp

HEADERS += QTransliter.h\
        qtransliter_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
