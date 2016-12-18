#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T20:30:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addownerswidget.cpp \
    aboutownerwidget.cpp \
    addcarswidget.cpp \
    aboutcarswidget.cpp \
    addmasterswidget.cpp \
    aboutmasterswidget.cpp \
    addjournalwidget.cpp \
    aboutjournalwidget.cpp


HEADERS  += mainwindow.h \
    addownerswidget.h \
    aboutownerwidget.h \
    addcarswidget.h \
    aboutcarswidget.h \
    addmasterswidget.h \
    aboutmasterswidget.h \
    addjournalwidget.h \
    aboutjournalwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
