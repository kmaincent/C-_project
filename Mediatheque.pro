QT += core
QT -= gui

CONFIG += c++11

TARGET = Mediatheque
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ressource_num.cpp \
    livre.cpp \
    ressource.cpp \
    revue.cpp \
    cd.cpp \
    dvd.cpp \
    mediatheque.cpp \
    vhs.cpp \
    enum_string_type.cpp \
    id_function.cpp

HEADERS += \
    ressource_num.h \
    livre.h \
    revue.h \
    ressource.h \
    cd.h \
    dvd.h \
    mediatheque.h \
    vhs.h \
    enum_string_type.h \
    include.h \
    id_function.h
