#include "entitiefactory.h"
#include "QString"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/Entity.h"


Entity* EntitieFactory::createEntitie(Entitie_Types t){
    Entity* e = NULL;
    switch(t){
        case 0:
            e = new Entity("Сущность "+QString::number(id++).toStdString());
            break;
        case 1:
            //e = this->scf->createCar();
            break;
        default:
            e = new Entity("Сущность "+QString::number(id++).toStdString());
    }
    DeleteFactory();
    return e;
}

EntitieFactory::EntitieFactory(){
    //this->scf = new SlowCarFactory();
}

EntitieFactory::~EntitieFactory(){
    //delete(this->scf);
}

EntitieFactory* EntitieFactory::entitieFactory(){
    if(factory==NULL){
        factory = new EntitieFactory();
    }
    return factory;
}

void EntitieFactory::DeleteFactory(){
    if(factory!=NULL){
        delete(factory);
        factory=NULL;
    }
}

void EntitieFactory::setGlobalId(int id0){
    id=id0;
    //SlowCar::setId(id);
    DeleteFactory();
}

EntitieFactory* EntitieFactory::factory = NULL;
int EntitieFactory::id = 0;
