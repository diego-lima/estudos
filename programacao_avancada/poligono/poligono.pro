TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sources/ponto.cpp \
    sources/poligono.cpp \
    sources/linha.cpp

HEADERS += \
    headers/ponto.h \
    headers/poligono.h \
    headers/linha.h
