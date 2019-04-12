TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    flightbooking.cpp \
        main.cpp \
    travelagency.cpp \
    rentalcarreservation.cpp \
    hotelbooking.cpp

HEADERS += \
    flightbooking.h \
    travelagency.h \
    rentalcarreservation.h \
    hotelbooking.h
