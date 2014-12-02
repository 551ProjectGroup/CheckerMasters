#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T08:36:33
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CheckersMaster
TEMPLATE = app
QMAKE_CXXFLAGS += -ggdb3 -pedantic -Wall --std=gnu++11 -Werror


SOURCES +=\
        mainwindow.cpp \
    boardstate.cpp \
    displayboard.cpp \
    guipiece.cpp \
    turn.cpp \
    UserInput.cpp \
    main.cpp

HEADERS  += mainwindow.h \
    boardstate.h \
    displayboard.h \
    guipiece.h \
    piece.h \
    struct.h \
    turn.h \
    userinput.h

FORMS    += mainwindow.ui
