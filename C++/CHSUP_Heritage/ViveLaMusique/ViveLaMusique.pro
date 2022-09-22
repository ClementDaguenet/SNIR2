TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        guitare.cpp \
        instrumentacordes.cpp \
        instrumentdemusique.cpp \
        main.cpp

HEADERS += \
    guitare.h \
    instrumentacordes.h \
    instrumentdemusique.h \
    libs.h
