#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T13:52:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SearchProject
TEMPLATE = app


SOURCES += main.cpp\
        controlwindow.cpp \
    displaywindow.cpp \
    mapoptions.cpp \
    Algorithm.cpp \
    astar.cpp \
    DFS.cpp \
    mapmaker.cpp

HEADERS  += controlwindow.h \
    displaywindow.h \
    mapoptions.h \
    Algorithm.h \
    astar.h \
    DFS.h \
    mapmaker.h

FORMS    += controlwindow.ui \
    displaywindow.ui \
    mapoptions.ui
