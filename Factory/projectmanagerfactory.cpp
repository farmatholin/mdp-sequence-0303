#include "projectmanagerfactory.h"
#include "Entities/projectmanager.h"

ProjectManagerFactory::ProjectManagerFactory()
{
}

Entity *ProjectManagerFactory::getProjectManager()
{
    return new ProjectManager();
}
