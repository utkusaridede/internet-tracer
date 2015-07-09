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
    systray.cpp \
    qcustomplot.cpp \
    kotaset.cpp \
    dialog.cpp

HEADERS  += \
    systray.h \
    qcustomplot.h \
    kotaset.h \
    dialog.h

FORMS    += \
    systray.ui \
    kotaset.ui \
    log.ui \
    dialog.ui
