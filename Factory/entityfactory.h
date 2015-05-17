#pragma once
#ifndef ENTITIEFACTORY_H
#define ENTITIEFACTORY_H

#include "Container/Entity.h"
#include "projectmanagerfactory.h"
#include "programmerfactory.h"
#include "designerfactory.h"
#include "qafactory.h"
#include "QMap"

enum{
    TYPE_EMPTY,
    TYPE_PROGRAMMER,
    TYPE_DESIGNER,
    TYPE_QA,
    TYPE_PROJECT_MANAGER
};

class EntityFactory{
private:
    static int id;
    explicit EntityFactory();
    virtual ~EntityFactory();
    static EntityFactory* factory;
    //===========================
    ProgrammerFactory* pf;
    DesignerFactory* df;
    QAFactory* qf;
    ProjectManagerFactory* pmf;
    //===========================

public:
    static EntityFactory* entityFactory();
    static void setGlobalId(int id0);
    static void DeleteFactory();
    Entity* createEntity(int t);
    static QMap<int,string> getAvaibleEntities();
};

#endif // ENTITIEFACTORY_H
