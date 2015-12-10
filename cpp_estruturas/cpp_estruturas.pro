TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    singlelist/slist.cpp \
    dlist/dlist.cpp

HEADERS += \
    singlelist/slist.h \
    singlelist/slist_testes.h \
    dlist/dlist.h

