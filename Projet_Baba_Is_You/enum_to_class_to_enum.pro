TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17 -pedantic-errors

SOURCES += \
        main.cpp
 #        position.cpp

HEADERS += \
    direction.h \
    position.h
