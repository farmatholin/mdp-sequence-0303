#include "projectmanagerfactory.h"
#include "Entities/projectmanager.h"

ProjectManagerFactory::ProjectManagerFactory()
{
}

Entitie *ProjectManagerFactory::getProjectManager()
{
    return new ProjectManager();
}
