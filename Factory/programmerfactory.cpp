#include "programmerfactory.h"

ProgrammerFactory::ProgrammerFactory()
{
}

Entity *ProgrammerFactory::createProgrammer()
{
    return new Programmer();
}
