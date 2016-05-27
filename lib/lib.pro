#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T21:00:06
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleExprParser
TEMPLATE = lib

CONFIG += c++11

DEFINES += SIMPLEEXPRPARSER_LIBRARY

SOURCES += specialspinbox.cpp \
    simplemathexprparser.cpp \
    specialintspinbox.cpp

HEADERS  += specialspinbox.h \
    simplemathexprparser.h \
    specialintspinbox.h \
    simpleexprparser_global.h
