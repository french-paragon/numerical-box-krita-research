#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T21:00:06
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleExprParser
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

DEFINES += SIMPLEEXPRPARSER_LIBRARY

SOURCES += simplemathexprparser.cpp \
        specialspinbox.cpp \
        specialintspinbox.cpp

HEADERS  += \
    simplemathexprparser.h \
    simpleexprparser_global.h \
    specialspinbox.h \
    specialintspinbox.h
