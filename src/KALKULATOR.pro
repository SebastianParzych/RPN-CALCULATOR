TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Inspector.cpp \
    calculation.cpp \
    conversion.cpp \
    interface.cpp \
        main.cpp \
    variable_x.cpp

HEADERS += \
    Inspector.h \
    calculation.h \
    conversion.h \
    interface.h \
    variable_x.h
