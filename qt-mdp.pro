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
    Container/Core.cpp \
    Factory/projectmanagerfactory.cpp \
    Container/SequenceDiagram.cpp \
    Entities/projectmanager.cpp \
    Entities/designer.cpp \
    Container/Entity.cpp \
    UI/uientity.cpp \
    UI/ui.cpp \
    Factory/entityfactory.cpp \
    Entities/programmer.cpp \
    Entities/qa.cpp \
    Factory/programmerfactory.cpp \
    Factory/designerfactory.cpp \
    Factory/qafactory.cpp \
    UI/function.cpp \
    UI/uiwork.cpp \
    UI/uisequence.cpp

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
    Entities/projectmanager.h \
    Entities/designer.h \
    Container/Entity.h \
    UI/uientity.h \
    UI/ui.h \
    Factory/entityfactory.h \
    Entities/programmer.h \
    Entities/qa.h \
    Factory/programmerfactory.h \
    Factory/designerfactory.h \
    Factory/qafactory.h \
    UI/function.h \
    UI/uiwork.h \
    UI/uisequence.h
FORMS    += mainwindow.ui
