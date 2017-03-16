#-------------------------------------------------
#
# Project created by QtCreator 2017-03-14T09:41:25
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConfigureSoftware
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    runsystem.cpp \
    canvos.cpp \
    projectlistwidget.cpp \
    primitive.cpp

HEADERS  += mainwindow.h \
    runsystem.h \
    canvos.h \
    primitive.h \
    projectlistwidget.h

FORMS    += mainwindow.ui \
    runsystem.ui

RESOURCES += \
    image.qrc
