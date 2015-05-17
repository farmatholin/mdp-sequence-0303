#include "qafactory.h"

QAFactory::QAFactory()
{
}

Entity *QAFactory::createQA(){
    return new QA();
}
