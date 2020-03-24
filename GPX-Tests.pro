TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wfatal-errors

HEADERS += \
    headers/earth.h \
    headers/geometry.h \
    headers/logs.h \
    headers/position.h \
    headers/route.h \
    headers/track.h \
    headers/types.h \
    headers/xml/parser.h \
    headers/xml/element.h \


SOURCES += \
    src/earth.cpp \
    src/gpx-tests.cpp \
    src/geometry.cpp \
    src/logs.cpp \
    src/position.cpp \
    src/route.cpp \
    src/track.cpp \
    src/xml/element.cpp \
    src/xml/parser.cpp \
    src/gpx-tests/name.cpp \
    src/gpx-tests/numpositions.cpp \
    src/gpx-tests/minElevation-N0815715.cpp \
    src/gpx-tests/name.cpp \
    src/gpx-tests/netHeightGain-T0084153.cpp \
    src/gpx-tests/netlength-T0112963.cpp \
    src/gpx-tests/numpositions.cpp \
    src/gpx-tests/totalLength-n0790170.cpp \
    src/gpx-tests/totalLength_N0815464.cpp \
    src/gpx-tests/totaltime_n0781255.cpp \
    src/gpx-tests/longestRest-T0103710.cpp \
    src/gpx-tests/minlatitude_n0743900.cpp \
    src/gpx-tests/findposition-t0117244.cpp

    src/gpx-tests/findposition-t0117244.cpp

INCLUDEPATH += headers/  headers/xml/

TARGET = $$_PRO_FILE_PWD_/execs/gpx-tests

LIBS += -lboost_unit_test_framework
