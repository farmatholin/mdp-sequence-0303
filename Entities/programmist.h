#ifndef PROGRAMMIST_H
#define PROGRAMMIST_H
#include "Container/Entity.h"

class Entity;
class Programmist : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    Programmist();
    ~Programmist();
};

#endif // PROGRAMMIST_H
