#pragma once
#ifndef PROJECTMANAGERFACTORY_H
#define PROJECTMANAGERFACTORY_H
#include "Container/Entity.h"

class ProjectManagerFactory
{
public:
    ProjectManagerFactory();
    Entity* getProjectManager();
};

#endif // PROJECTMANAGERFACTORY_H
