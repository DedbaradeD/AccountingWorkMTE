#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T16:28:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AccountingWorkMTE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drivers.cpp \
    newdriver.cpp \
    motortransport.cpp \
    newmotortransport.cpp \
    routes.cpp \
    newroute.cpp \
    employeddrivers.cpp \
    searchemployeddrivers.cpp \
    vehiclesmileage.cpp \
    searchvehiclemileage.cpp \
    travelsheets.cpp \
    searchtravelsheets.cpp \
    otherworkers.cpp \
    newotherworker.cpp \
    checkinworktime.cpp \
    employedotherworkers.cpp \
    searchemployedotherworker.cpp \
    travelsheet.cpp \
    registertravelsheets.cpp \
    aboutprogram.cpp \
    summarylogbybrand.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    drivers.h \
    newdriver.h \
    motortransport.h \
    newmotortransport.h \
    routes.h \
    newroute.h \
    employeddrivers.h \
    searchemployeddrivers.h \
    vehiclesmileage.h \
    searchvehiclemileage.h \
    travelsheets.h \
    searchtravelsheets.h \
    otherworkers.h \
    newotherworker.h \
    checkinworktime.h \
    employedotherworkers.h \
    searchemployedotherworker.h \
    travelsheet.h \
    registertravelsheets.h \
    aboutprogram.h \
    summarylogbybrand.h \
    help.h

FORMS    += mainwindow.ui \
    drivers.ui \
    newdriver.ui \
    motortransport.ui \
    newmotortransport.ui \
    routes.ui \
    newroute.ui \
    employeddrivers.ui \
    searchemployeddrivers.ui \
    vehiclesmileage.ui \
    searchvehiclemileage.ui \
    travelsheets.ui \
    searchtravelsheets.ui \
    otherworkers.ui \
    newotherworker.ui \
    checkinworktime.ui \
    employedotherworkers.ui \
    searchemployedotherworker.ui \
    travelsheet.ui \
    registertravelsheets.ui \
    aboutprogram.ui \
    summarylogbybrand.ui \
    help.ui

RESOURCES = AccountingWorkMTE.qrc
