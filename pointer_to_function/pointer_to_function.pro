TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    sort_tool.c

HEADERS += \
    sort_tool.h

DISTFILES += \
    notes.txt
