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
    mapoptions.cpp \
    astar.cpp \
    mapmaker.cpp \
    simpleSearch.cpp \
    Algorithm.cpp \
    bfswindow.cpp \
    astarwindow.cpp \
    hcoord.cpp \
    dfswindow.cpp

HEADERS  += controlwindow.h \
    mapoptions.h \
    astar.h \
    mapmaker.h \
    simpleSearch.h \
    Algorithm.h \
    bfswindow.h \
    astarwindow.h \
    hcoord.h \
    dfswindow.h

FORMS    += controlwindow.ui \
    mapoptions.ui \
    bfswindow.ui \
    astarwindow.ui \
    dfswindow.ui

CONFIG += c++11
