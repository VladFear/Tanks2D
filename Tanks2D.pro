TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf

SOURCES += main.cpp \
    window.cpp \
    gameobject.cpp \
    tank.cpp \
    texturemanager.cpp \
    map.cpp

HEADERS += \
    window.h \
    gameobject.h \
    tank.h \
    texturemanager.h \
    map.h

RESOURCES +=
