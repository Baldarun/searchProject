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
    astar.cpp \
    mapmaker.cpp \
    simpleSearch.cpp \
    Algorithm.cpp \
    bfswindow.cpp \
    astarwindow.cpp

HEADERS  += controlwindow.h \
    displaywindow.h \
    mapoptions.h \
    astar.h \
    mapmaker.h \
    simpleSearch.h \
    Algorithm.h \
    bfswindow.h \
    astarwindow.h

FORMS    += controlwindow.ui \
    displaywindow.ui \
    mapoptions.ui \
    bfswindow.ui \
    astarwindow.ui
