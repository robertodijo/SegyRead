#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T22:41:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = segyread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    util.cpp \
    csegy.cpp

HEADERS  += mainwindow.h \
    csegy.h \
    util.h \
    GBK.h

FORMS    += mainwindow.ui

RESOURCES += \
    segyread.qrc
