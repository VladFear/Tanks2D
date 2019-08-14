TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2

SOURCES += main.cpp \
    window.cpp \
    gameobject.cpp

HEADERS += \
    window.h \
    gameobject.h
