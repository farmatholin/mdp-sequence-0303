#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Container/Entity.h"

class Entity;
class ProjectManager : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    ProjectManager();
    ~ProjectManager();
};

#endif // PROJECTMANAGER_H
