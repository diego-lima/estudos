TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += charts

SOURCES += main.cpp \
    sources/ponto.cpp \
    sources/poligono.cpp \
    sources/linha.cpp \
    sources/mostrador.cpp

HEADERS += \
    headers/ponto.h \
    headers/poligono.h \
    headers/linha.h \
    headers/mostrador.h
