TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animation.cpp \
        entity.cpp \
        eplayable.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        main.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    animation.h \
    entity.h \
    eplayable.h \
    gameinstance.h \
    gamestate.h \
    sfaseteste1.h \
    smainmenu.h
