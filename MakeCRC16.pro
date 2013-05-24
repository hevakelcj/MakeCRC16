#-------------------------------------------------
#
# Project created by QtCreator 2013-05-24T06:50:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakeCRC16
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    Util/crc16.c

HEADERS  += dialog.h \
    Util/crc16.h \
    type.h

FORMS    += dialog.ui
