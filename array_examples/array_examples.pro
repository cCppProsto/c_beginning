TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

QMAKE_CFLAGS += -std=c11

HEADERS += \
    example_1.h \
    time_chrono.h \
    example_2.h \
    example_3.h

DISTFILES += \
    notes.txt
