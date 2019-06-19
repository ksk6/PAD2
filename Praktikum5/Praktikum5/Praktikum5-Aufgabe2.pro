#-------------------------------------------------
#
# Project created by QtCreator 2019-06-17T09:15:12
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Praktikum5-Aufgabe2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        booking.cpp \
        customer.cpp \
        flightbooking.cpp \
        hotelbooking.cpp \
        main.cpp \
        mainwindow.cpp \
        rentalcarreservation.cpp \
        test.cpp \
        travel.cpp \
        travelagency.cpp \
    addbookingdialog.cpp \
    algorithmen.cpp \
    heap.cpp \
    checkdialog.cpp

HEADERS += \
        addbookingdialog.h \
        booking.h \
        customer.h \
        flightbooking.h \
        hotelbooking.h \
        list.h \
        mainwindow.h \
        node.h \
        rentalcarreservation.h \
        test.h \
        travel.h \
        travelagency.h \
        ui_addbookingdialog.h \
        ui_mainwindow.h \
    graph.h \
    heap.h \
    checkdialog.h

FORMS += \
        addbookingdialog.ui \
        mainwindow.ui \
    checkdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    airports.txt \
    bookings_praktikum4.txt \
    bookings_praktikum5.txt
