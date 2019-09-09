TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wunused-parameter

SOURCES += \
        animation.cpp \
        edoor.cpp \
        eitem.cpp \
        enonplayable.cpp \
        entity.cpp \
        eplayable.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        inventory.cpp \
        main.cpp \
        resourcemanager.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp \
        sworld.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    animation.h \
    edoor.h \
    eitem.h \
    enonplayable.h \
    entity.h \
    eplayable.h \
    gameinstance.h \
    gamestate.h \
    inventory.h \
    resourcemanager.h \
    sfaseteste1.h \
    smainmenu.h \
    sworld.h
