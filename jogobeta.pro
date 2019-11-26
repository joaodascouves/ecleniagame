TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wunused-parameter -std=gnu++17

SOURCES += \
        animation.cpp \
        edialogbox.cpp \
        edoor.cpp \
        eitem.cpp \
        enonplayable.cpp \
        enonplayablehitable.cpp \
        entity.cpp \
        epanel.cpp \
        eplayable.cpp \
        es1banshee.cpp \
        es1ghost.cpp \
        es1locker.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        inventory.cpp \
        main.cpp \
        resourcemanager.cpp \
        scombat.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp \
        spawnmanager.cpp \
        sworld.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

HEADERS += \
    animation.h \
    edialogbox.h \
    edoor.h \
    eitem.h \
    enonplayable.h \
    enonplayablehitable.h \
    entity.h \
    epanel.h \
    eplayable.h \
    es1banshee.h \
    es1ghost.h \
    es1locker.h \
    gameinstance.h \
    gamestate.h \
    inventory.h \
    resourcemanager.h \
    scombat.h \
    sfaseteste1.h \
    smainmenu.h \
    spawnmanager.h \
    sworld.h
