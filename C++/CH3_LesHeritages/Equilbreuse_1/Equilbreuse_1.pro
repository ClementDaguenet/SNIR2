TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        codeur.cpp \
        equilibreuse.cpp \
        main.cpp \
        mcculdaq.cpp \
        moteur.cpp

HEADERS += \
    codeur.h \
    equilibreuse.h \
    libs.h \
    mcculdaq.h \
    moteur.h
