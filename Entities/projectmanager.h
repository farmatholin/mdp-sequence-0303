#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Container/Entitie.h"

class Entitie;
class ProjectManager : public Entitie{
private:
    static int id;
public:
    static void setId(int id0);
    ProjectManager();
    ~ProjectManager();
};

#endif // PROJECTMANAGER_H
