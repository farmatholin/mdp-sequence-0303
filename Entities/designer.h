#ifndef DESIGNER_H
#define DESIGNER_H
#include "Container/Entitie.h"

class Entitie;
class Designer : public Entitie{
private:
    static int id;
public:
    static void setId(int id0);
    Designer();
    ~Designer();
};

#endif // DESIGNER_H
