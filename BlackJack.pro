TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        actionSelection.cpp \
        main.cpp \
        dealer.cpp \
        deck.cpp \
        game.cpp \
        player.cpp \
        q-learning.cpp

HEADERS += \
        actionSelection.h \
        dealer.h \
        deck.h \
        game.h \
        player.h \
        q-learning.h

