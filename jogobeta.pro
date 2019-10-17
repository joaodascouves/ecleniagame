TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wunused-parameter

SOURCES += \
        animation.cpp \
        edialogbox.cpp \
        edoor.cpp \
        eitem.cpp \
        enonplayable.cpp \
        enonplayablehitable.cpp \
        entity.cpp \
        eplayable.cpp \
        es1banshee.cpp \
        es1ghost.cpp \
        es1locker.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        inventory.cpp \
        main.cpp \
        resourcemanager.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp \
        spawnmanager.cpp \
        sworld.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    animation.h \
    edialogbox.h \
    edoor.h \
    eitem.h \
    enonplayable.h \
    enonplayablehitable.h \
    entity.h \
    eplayable.h \
    es1banshee.h \
    es1ghost.h \
    es1locker.h \
    gameinstance.h \
    gamestate.h \
    inventory.h \
    resourcemanager.h \
    sfaseteste1.h \
    smainmenu.h \
    spawnmanager.h \
    sworld.h
