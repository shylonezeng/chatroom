#-------------------------------------------------
#
# Project created by QtCreator 2014-09-22T20:08:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my_chatroom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    my_lib/mylib.cpp

HEADERS  += mainwindow.h \
    client.h \
    my_lib/mylib.h

FORMS    += mainwindow.ui
