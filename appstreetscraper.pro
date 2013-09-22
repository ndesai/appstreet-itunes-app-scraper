#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T10:52:34
#
#-------------------------------------------------

QT       += core network xml sql

QT       -= gui

TARGET = appstreetscraper
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scraper.cpp \
    itunesappcontenthandler.cpp \
    sourceurlmanager.cpp \
    itunesappobject.cpp \
    databasemanager.cpp

HEADERS += \
    scraper.h \
    itunesappcontenthandler.h \
    sourceurlmanager.h \
    itunesappobject.h \
    databasemanager.h
