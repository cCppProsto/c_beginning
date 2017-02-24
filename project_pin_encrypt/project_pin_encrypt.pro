TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    pin_encrypt.c

HEADERS += \
    pin_encrypt.h

DISTFILES += \
    notes.txt
