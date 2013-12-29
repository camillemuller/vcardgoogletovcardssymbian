#-------------------------------------------------
#
# Project created by QtCreator 2013-12-29T13:44:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vcardgoogletovcardsymbian
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controleur.cpp \
    parseurvcard.cpp

HEADERS  += mainwindow.h \
    controleur.h \
    parseurvcard.h

FORMS    += mainwindow.ui
