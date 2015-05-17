#ifndef PROGRAMMERFACTORY_H
#define PROGRAMMERFACTORY_H
#include "Container/Entity.h"
#include "Entities/programmer.h"

class ProgrammerFactory{
public:
    ProgrammerFactory();
    Entity* createProgrammer();
};

#endif // PROGRAMMERFACTORY_H
