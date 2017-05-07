QT += core
QT -= gui

CONFIG += c++11

TARGET = oop
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    container.h \
    base.h \
    shapes.h
