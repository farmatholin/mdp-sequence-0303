#ifndef QAFACTORY_H
#define QAFACTORY_H
#include "Container/Entity.h"
#include "Entities/qa.h"

class QAFactory
{
public:
    QAFactory();
    Entity* createQA();
};

#endif // QAFACTORY_H
