#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T18:34:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        controlwindow.cpp \
    Algorithm.cpp \
    DFS.cpp \
    displaywindow.cpp \
    mapoptions.cpp

HEADERS  += controlwindow.h \
    Algorithm.h \
    DFS.h \
    displaywindow.h \
    mapoptions.h

FORMS    += controlwindow.ui \
    displaywindow.ui \
    mapoptions.ui

DISTFILES +=
