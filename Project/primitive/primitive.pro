#-------------------------------------------------
#
# Project created by QtCreator 2017-01-19T10:15:49
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = primitive
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    primitive.cpp \
    canvos.cpp \
    projectlistwidget.cpp

HEADERS  += mainwindow.h \
    primitive.h \
    canvos.h \
    projectlistwidget.h

FORMS    += mainwindow.ui
