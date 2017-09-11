TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += p1specialized.cpp

LIBS += -LC:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\newblas -llibblas
LIBS += -LC:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\newblas -lliblapack

INCLUDEPATH += C:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\include
DEPENDPATH += C:\Users\Davide\Documents\Armadillo\armadillo-8.100.1\include

#LIBS += -LC:\Armadillo\newblas\ -llibblas
#LIBS += -LC:\Armadillo\newblas\ -lliblapack

#INCLUDEPATH += C:\Armadillo\include
#DEPENDPATH += C:\Armadillo\include
