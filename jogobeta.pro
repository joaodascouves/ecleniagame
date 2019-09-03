TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        entity.cpp \
        eplayable.cpp \
        gameinstance.cpp \
        gamestate.cpp \
        main.cpp \
        sfaseteste1.cpp \
        smainmenu.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    entity.h \
    eplayable.h \
    gameinstance.h \
    gamestate.h \
    sfaseteste1.h \
    smainmenu.h
