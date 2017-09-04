#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T21:41:29
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Excercise
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    worker.h \
    common.h

FORMS    += mainwindow.ui
CONFIG += c++11
