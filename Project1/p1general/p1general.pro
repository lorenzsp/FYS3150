TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += p1general.cpp

LIBS += -LC:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\newblas -llibblas
LIBS += -LC:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\newblas -lliblapack

INCLUDEPATH += C:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\include
DEPENDPATH += C:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\include
