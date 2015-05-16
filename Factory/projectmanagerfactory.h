#pragma once
#ifndef PROJECTMANAGERFACTORY_H
#define PROJECTMANAGERFACTORY_H
#include "Container/Entitie.h"

class ProjectManagerFactory
{
public:
    ProjectManagerFactory();
    Entitie* getProjectManager();
};

#endif // PROJECTMANAGERFACTORY_H
