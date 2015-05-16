#pragma once
#ifndef ENTITIEFACTORY_H
#define ENTITIEFACTORY_H

#include "Container/Entity.h"

enum Entity_Types{
    _Empty,
    _Programmer,
    _Desiner,
    _Tester,
    _ProjectManager
};

class EntityFactory{
private:
    static int id;
    explicit EntityFactory();
    virtual ~EntityFactory();
    static EntityFactory* factory;
    //===========================
    //ProgrammerFactory* pf;
    //DesignerFactory* df;
    //TesterFactory* tf;
    //ProjectManagerFactory* pmf;
    //===========================

public:
    static EntityFactory* entitieFactory();
    static void setGlobalId(int id0);
    static void DeleteFactory();
    Entity* createEntity(Entity_Types t);
};

#endif // ENTITIEFACTORY_H
