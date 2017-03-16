#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T16:50:46
#
#-------------------------------------------------

QT       += widgets svg

TARGET = primitiveLib
TEMPLATE = lib

CONFIG += c++11

DEFINES += PRIMITIVELIB_LIBRARY

SOURCES += primitivelib.cpp \
    primitive.cpp \
    tankprimitive.cpp \
    fireprimitive.cpp \
    horizontalpipeprimitive.cpp \
    teeprimitive.cpp \
    verticalprimitive.cpp \
    curveprimitive.cpp \
    buildingprimitive.cpp \
    elevatedtankprimitive.cpp \
    palmtreeprimitive.cpp \
    textprimitive.cpp \
    attributedialog.cpp \
    linechartprimitive.cpp

HEADERS +=\
        primitivelib_global.h \
    primitive.h \
    tankprimitive.h \
    fireprimitive.h \
    horizontalpipeprimitive.h \
    teeprimitive.h \
    verticalprimitive.h \
    curveprimitive.h \
    buildingprimitive.h \
    elevatedtankprimitive.h \
    palmtreeprimitive.h \
    textprimitive.h \
    attributedialog.h \
    linechartprimitive.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    image.qrc

FORMS += \
    attributedialog.ui
