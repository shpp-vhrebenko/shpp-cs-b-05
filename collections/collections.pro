#-------------------------------------------------
#
# Project created by QtCreator 2015-11-06T16:29:34
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = collections
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    Mylist.h \
    MyVector.h \
    MySteck.h \
    MyQueue.h \
    MyDeque.h \
    mydual-linklist.h \
    mypriorityqueue.h \
    mybinarysearchtree.h \
    nodetree.h \
    myhashmap.h \
    hashnode.h
QMAKE_CXXFLAGS += -std=c++0x
