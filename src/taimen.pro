TEMPLATE = app
TARGET = taimen

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp window.cpp
HEADERS += window.hpp 
