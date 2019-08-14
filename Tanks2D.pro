TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2 -lSDL2_image -lpthread

SOURCES += main.cpp \
    window.cpp \
    gameobject.cpp \
    tank.cpp

HEADERS += \
    window.h \
    gameobject.h \
    tank.h

RESOURCES +=
