TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        arc.cpp \
        element.cpp \
        main.cpp \
        pause.cpp \
        segment.cpp \
        trajectoire.cpp \
        vecteur.cpp

HEADERS += \
    arc.h \
    element.h \
    libs.h \
    pause.h \
    segment.h \
    trajectoire.h \
    vecteur.h
