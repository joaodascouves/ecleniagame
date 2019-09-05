TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wunused-parameter

SOURCES += \
        animation.cpp \
        edoor.cpp \
        entity.cpp \
        eplayable.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        main.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp \
        sworld.cpp \
        texturemanager.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    animation.h \
    edoor.h \
    entity.h \
    eplayable.h \
    gameinstance.h \
    gamestate.h \
    sfaseteste1.h \
    smainmenu.h \
    sworld.h \
    texturemanager.h
