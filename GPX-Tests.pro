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
    headers/xml/element.h

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
    src/gpx-tests/minlatitude-n0806708.cpp\
    src/gpx-tests/maxLongitude-n0804090.cpp \
    src/gpx-tests/minLongitude-N0786072.cpp \
    src/gpx-tests/travellingTime-N0800790.cpp \
    src/gpx-tests/maxElevation-n0792395.cpp \
 #    src/gpx-tests/minElevation-n0806748.cpp \
#   src/gpx-tests/maxlongitude-n0799125.cpp \ As per Neil's request
#     src/gpx-tests/maxlatitude-n0798917.cpp \
#     src/gpx-tests/totalLength-n0786783.cpp  \
 #    src/gpx-tests/maxElevation-N0792831.cpp \
    src/gpx-tests/travellingTime-N0800790.cpp \
    src/gpx-tests/maxElevation-n0809215.cpp \
#     src/gpx-tests/minLongitude-n0782914.cpp \
    src/gpx-tests/totalheightgain_n0800619.cpp \
#     src/gpx-tests/minlatitude-n0786956.cpp \
#   src/gpx-tests/minlongitude-n0783935.cpp Commented self out as to not break anyone else's code


INCLUDEPATH += headers/  headers/xml/

TARGET = $$_PRO_FILE_PWD_/execs/gpx-tests

LIBS += -lboost_unit_test_framework

