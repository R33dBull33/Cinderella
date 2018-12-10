#-------------------------------------------------
#
# Project created by QtCreator 2018-12-07T09:33:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cinderella
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    hinzufuegen.cpp

HEADERS  += mainwindow.h \
    database.h \
    hinzufuegen.h

FORMS    += mainwindow.ui \
    hinzufuegen.ui
