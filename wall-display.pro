#-------------------------------------------------
#
# Project created by QtCreator 2014-06-24T14:53:35
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wall-display
TEMPLATE = app


SOURCES += main.cpp\
        walldisplay.cpp \
    walldisplaysettings.cpp

HEADERS  += walldisplay.h \
    walldisplaysettings.h

FORMS    += walldisplay.ui \
    walldisplaysettings.ui

RESOURCES += \
    resources.qrc
