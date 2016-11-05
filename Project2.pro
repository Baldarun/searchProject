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
    astar.cpp \
    mapmaker.cpp \
    mapoptions.cpp \
    mapwindow.cpp

HEADERS  += controlwindow.h \
    Algorithm.h \
    DFS.h \
    displaywindow.h \
    astar.h \
    mapmaker.h \
    mapoptions.h \
    mapwindow.h

FORMS    += controlwindow.ui \
    displaywindow.ui \
    mapoptions.ui

DISTFILES +=
