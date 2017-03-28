TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_LFLAGS += -static-libgcc

SOURCES += main.c
