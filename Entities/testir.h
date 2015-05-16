#ifndef TESTIR_H
#define TESTIR_H
#include "Container/Entitie.h"

class Entitie;
class Testir : public Entitie{
private:
    static int id;
public:
    static void setId(int id0);
    Testir();
    ~Testir();
};

#endif // TESTIR_H
