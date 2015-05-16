#ifndef QA_H
#define QA_H
#include "Container/Entity.h"

class Entity;
class QA : public Entity{
private:
    static int id;
public:
    static void setId(int id0);
    QA();
    ~QA();
};

#endif
