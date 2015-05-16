#pragma once
#ifndef ENTITIEFACTORY_H
#define ENTITIEFACTORY_H

#include "Container/Entitie.h"

enum Entitie_Types{
    _Empty,
    _Programmer,
    _Desiner,
    _Tester,
    _ProjectManager
};

class EntitieFactory{
private:
    static int id;
    explicit EntitieFactory();
    virtual ~EntitieFactory();
    static EntitieFactory* factory;
    //===========================
    ProgrammerFactory* pf;
    DesignerFactory* df;
    TesterFactory* tf;
    ProjectManagerFactory* pmf;
    //===========================

public:
    static EntitieFactory* entitieFactory();
    static void setGlobalId(int id0);
    static void DeleteFactory();
    Entitie* createEntitie(Entitie_Types t);
};

#endif // ENTITIEFACTORY_H
