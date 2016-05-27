#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T12:55:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = essaiCalculALaVolee
TEMPLATE = app

CONFIG += c++11

DEPENDPATH += . ../lib
INCLUDEPATH += ../lib
LIBS += -L../lib -lsimpleExprParser

SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \

FORMS    += mainwindow.ui
