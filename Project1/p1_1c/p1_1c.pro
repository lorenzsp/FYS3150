TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    p1_1c.cpp \
    ../p1_1b/alloc.cpp

HEADERS += \
    ../p1_1b/alloc.h
INCLUDEPATH C:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\include
LIBS += -LC:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\examples\lib_win64 -llapack_win64_MT -lblas_win64_MT
