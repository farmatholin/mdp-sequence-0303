#include "projectmanagerfactory.h"
#include "Entities/projectmanager.h"

ProjectManagerFactory::ProjectManagerFactory()
{
}

Entity *ProjectManagerFactory::createProjectManager()
{
    return new ProjectManager();
}
