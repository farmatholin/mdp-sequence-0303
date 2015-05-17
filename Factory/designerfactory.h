#ifndef DESIGNERFACTORY_H
#define DESIGNERFACTORY_H
#include "Entities/designer.h"
#include "Container/Entity.h"

class DesignerFactory
{
public:
    DesignerFactory();
    Entity *createDesigner();
};

#endif // DESIGNERFACTORY_H
