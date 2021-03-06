#-------------------------------------------------
#
# Project created by QtCreator 2013-09-10T20:28:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vns_kma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parsanddrow.cpp \
    pc.cpp \
    switch.cpp \
    router.cpp \
    connects.cpp \
    routersetting.cpp \
    pcseting.cpp \
    switchseting.cpp

HEADERS  += mainwindow.h \
    parsanddrow.h \
    switch.h \
    pc.h \
    router.h \
    connects.h \
    routersetting.h \
    pcseting.h \
    switchseting.h

FORMS    += mainwindow.ui \
    routersetting.ui \
    pcseting.ui \
    switchseting.ui
