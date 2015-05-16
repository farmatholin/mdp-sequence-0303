#ifndef PROGRAMMIST_H
#define PROGRAMMIST_H
#include "Container/Entitie.h"

class Entitie;
class Programmist : public Entitie{
private:
    static int id;
public:
    static void setId(int id0);
    Programmist();
    ~Programmist();
};

#endif // PROGRAMMIST_H
