#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T15:38:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qThermostat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wineventschedule.cpp \
    qclickablelabel.cpp

HEADERS  += mainwindow.h \
    wineventschedule.h \
    qclickablelabel.h

FORMS    += mainwindow.ui \
    wineventschedule.ui
