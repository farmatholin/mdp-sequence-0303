#include "entitiefactory.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/Entitie.h"


Entitie* EntitieFactory::createEntitie(Entitie_Types t){
    Entitie* e = NULL;
    switch(t){
        case 0:
            e = new Entitie("Сущность "+QString::number(id++).toStdString());
            break;
        case 1:
            //e = this->scf->createCar();
            break;
        default:
            e = new Entitie("Сущность "+QString::number(id++).toStdString());
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
