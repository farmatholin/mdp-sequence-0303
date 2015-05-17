#include "entityfactory.h"
#include "QString"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/Entity.h"


Entity* EntityFactory::createEntity(int t){
    Entity* e = NULL;
    switch(t){
        case TYPE_PROJECT_MANAGER:
            e = this->pmf->createProjectManager();
            break;
        case TYPE_EMPTY:
        default:
            e = new Entity("Сущность "+QString::number(id++).toStdString());
    }
    DeleteFactory();
    return e;
}

QMap<int, string> EntityFactory::getAvaibleEntities(){
    QMap<int, string> map;
    map.insert(TYPE_DESIGNER,"Дизайнер");
    map.insert(TYPE_PROGRAMMER,"Программист");
    map.insert(TYPE_QA,"Тестировщик");
    map.insert(TYPE_PROJECT_MANAGER,"PM");

    return map;
}

EntityFactory::EntityFactory(){
    this->pmf = new ProjectManagerFactory();
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
    DeleteFactory();
}

EntityFactory* EntityFactory::factory = NULL;
int EntityFactory::id = 0;
