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
    Container/DoubleField.cpp \
    Container/Field.cpp \
    Container/IntField.cpp \
    Container/Sequence.cpp \
    Container/StringField.cpp \
    Container/Work.cpp \
    Container/oldmain.cpp \
    Container/Core.cpp \
    Factory/projectmanagerfactory.cpp \
    Container/SequenceDiagram.cpp \
    Entities/projectmanager.cpp \
    Entities/programmist.cpp \
    Entities/designer.cpp \
    Entities/testir.cpp \
    Container/Entity.cpp \
    uientity.cpp \
    Factory/entityfactory.cpp

HEADERS  += mainwindow.h \
    Container/DataField.h \
    Container/DoubleField.h \
    Container/Field.h \
    Container/IntField.h \
    Container/List.h \
    Container/ListItem.h \
    Container/Sequence.h \
    Container/StringField.h \
    Container/Work.h \
    Container/Core.h \
    Factory/projectmanagerfactory.h \
    Container/SequenceDiagram.h \
    Entitys/projectmanager.h \
    Entitys/programmist.h \
    Entitys/designer.h \
    Entitys/testir.h \
    Container/Entity.h \
    uientity.h \
    Factory/entityfactory.h
FORMS    += mainwindow.ui
