#pragma once
#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Container/Entity.h"

class Entity;
class Programmer : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    Programmer();
    ~Programmer();
};

#endif // PROGRAMMIST_H
