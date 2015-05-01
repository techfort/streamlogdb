TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x
#QMAKE_CXXFLAGS += -Wfatal-errors

SOURCES += main.cpp \
    core/streamlog.cpp \
    core/event.cpp

HEADERS += \
    core/streamlog.h \
    core/event.h

