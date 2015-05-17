#include "designerfactory.h"

DesignerFactory::DesignerFactory()
{
}

Entity *DesignerFactory::createDesigner(){
    return new Designer();
}
