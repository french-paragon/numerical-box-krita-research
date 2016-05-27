#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T20:57:26
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_simplemathparsertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG += c++11

DEPENDPATH += . ../lib
INCLUDEPATH += ../lib
LIBS += -L../lib -lsimpleExprParser


SOURCES += tst_simplemathparsertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
