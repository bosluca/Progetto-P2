
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utente.cpp \
    articolo.cpp \
    base.cpp \
    premium.cpp

HEADERS += \
    utente.h \
    articolo.h \
    base.h \
    premium.h
CONFIG += qt

QT += svg
