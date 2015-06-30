#-------------------------------------------------
#
# Project created by QtCreator 2015-06-30T13:58:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systray.cpp

HEADERS  += mainwindow.h \
    systray.h

FORMS    += mainwindow.ui \
    systray.ui
