#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T17:13:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-mdp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        entity.cpp \
    Container/DoubleField.cpp \
    Container/Entitie.cpp \
    Container/Field.cpp \
    Container/IntField.cpp \
    Container/Sequence.cpp \
    Container/SequenceDiagramm.cpp \
    Container/StringField.cpp \
    Container/Work.cpp \
    Container/oldmain.cpp \
    Container/Core.cpp

HEADERS  += mainwindow.h \
        entity.h \
    Container/DataField.h \
    Container/DoubleField.h \
    Container/Entitie.h \
    Container/Field.h \
    Container/IntField.h \
    Container/List.h \
    Container/ListItem.h \
    Container/Sequence.h \
    Container/SequenceDiagramm.h \
    Container/StringField.h \
    Container/Work.h \
    Container/Core.h

FORMS    += mainwindow.ui
