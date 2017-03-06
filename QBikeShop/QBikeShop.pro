
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utente.cpp \
    articolo.cpp \
    base.cpp \
    premium.cpp \
    database.cpp \
    contenitore.cpp

HEADERS += \
    utente.h \
    articolo.h \
    base.h \
    premium.h \
    database.h \
    contenitore.h
CONFIG += qt

QT += svg
