#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T12:04:30
#
#-------------------------------------------------

QT       += core gui
LIBS += -lws2_32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3Dgant
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qxtspanslider.cpp \
    task.cpp \
    taskfilereader.cpp

HEADERS  += mainwindow.h \
    qxtglobal.h  qxtnamespace.h  qxtspanslider.h  qxtspanslider_p.h \
    task.h \
    taskfilereader.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc
