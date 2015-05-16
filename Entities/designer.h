#ifndef DESIGNER_H
#define DESIGNER_H
#include "Container/Entity.h"

class Entity;
class Designer : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    Designer();
    ~Designer();
};

#endif // DESIGNER_H
