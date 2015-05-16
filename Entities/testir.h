#ifndef TESTIR_H
#define TESTIR_H
#include "Container/Entity.h"

class Entity;
class Testir : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    Testir();
    ~Testir();
};

#endif // TESTIR_H
