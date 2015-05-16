#include "Core.h"
#include "Entity.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "qmath.h"
#include <QFile>
#include <QString>
#include <QDataStream>
#include <QIODevice>
#include <QByteArray>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <QCryptographicHash>

Core::Core(){
    this->content = new SequenceDiagram("Common");
    this->state = 0;
}

Core::~Core(){
    delete(this->content);
}

int Core::getEntitiesCount(){
    return this->content->getEntitiesCount();
}

int Core::getWorksCount(){
    return this->content->getWorksCount();
}

int Core::getSequencesCount(){
    return this->content->getSequencesCount();
}

List<Entity*>* Core::getAllEntities(){
    return this->content->getAllEntities();
}

void Core::addEntity(string ID){
    this->content->addEntity(ID);
}

void Core::addUserEntity(Entity *e){
    this->content->addUserEntity(e);
}

Entity* Core::entitieAt(int i){
    return this->content->entitieAt(i);
}

Entity* Core::entitieById(string ID){
    return this->content->entitieById(ID);
}

void Core::popEntityAt(int i){
    this->content->popSequenceAt(i);
}

void Core::popEntityByID(string ID){
    this->content->popEntityByID(ID);
}

int Core::getEntityIndexByID(string ID){
    return this->content->getEntityIndexByID(ID);
}

void Core::addWork(string ID, double workTime, Entity *to){
   this->content->addWork(ID,workTime, to);
}

void Core::addUserWork(Work *work){
    this->content->addUserWork(work);
}

Work* Core::getWorkAt(int i){
    return this->content->getWorkAt(i);
}

Work* Core::getWorkByID(string ID){
    return this->content->getWorkByID(ID);
}

void Core::popWorkAt(int i){
    this->content->popWorkAt(i);
}

void Core::popWorkByID(string ID){
    this->content->popWorkByID(ID);
}

int Core::getWorkIndexByID(string ID){
    return this->content->getWorkIndexByID(ID);
}

void Core::addUserSequence(Sequence* s){
    this->content->addUserSequence(s);
}

void Core::addSequence(string ID, string name, Work *workFrom, Work *workTo){
   this->content->addSequence(ID,name,workFrom,workTo);
}

Sequence *Core::sequenceAt(int i){
    return this->content->sequenceAt(i);
}

Sequence *Core::sequenceByID(string ID){
    return this->content->sequenceByID(ID);
}

void Core::popSequenceAt(int i){
    this->content->popSequenceAt(i);
}

void Core::popSequenceByID(string ID){
    this->content->popSequenceByID(ID);
}

int Core::getIndexSequenceByID(string ID){
    return this->content->getIndexSequenceByID(ID);
}
