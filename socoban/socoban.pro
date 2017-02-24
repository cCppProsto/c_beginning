TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    socoban_menu.c \
    ../../tools_src/input_tools.c \
    levels_data.c \
    socoban_levels.c

HEADERS += \
    socoban_menu.h \
    ../../tools_src/input_tools.h \
    socoban_levels.h
