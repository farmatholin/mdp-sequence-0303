#include "entityfactory.h"
#include "QString"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/Entity.h"


Entity* EntityFactory::createEntity(Entity_Types t){
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

EntityFactory::EntityFactory(){
    //this->scf = new SlowCarFactory();
}

EntityFactory::~EntityFactory(){
    //delete(this->scf);
}

EntityFactory* EntityFactory::entitieFactory(){
    if(factory==NULL){
        factory = new EntityFactory();
    }
    return factory;
}

void EntityFactory::DeleteFactory(){
    if(factory!=NULL){
        delete(factory);
        factory=NULL;
    }
}

void EntityFactory::setGlobalId(int id0){
    id=id0;
    //SlowCar::setId(id);
    DeleteFactory();
}

EntityFactory* EntityFactory::factory = NULL;
int EntityFactory::id = 0;
