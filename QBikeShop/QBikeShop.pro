
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utente.cpp \
    articolo.cpp

HEADERS += \
    utente.h \
    articolo.h
CONFIG += qt

QT += svg
