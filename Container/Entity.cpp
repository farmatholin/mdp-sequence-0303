#include "Entity.h"

//=====================================================
#include "Field.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "Work.h"
//=====================================================


Entity::Entity(string ID){
    this->ID = ID;
    this->myfield = new List<Field*>();
    this->myWork = new List<Work*>();
}

Entity::~Entity(){
    for(int i=0; i<this->myfield->size(); i++){
        delete(myfield->at(i));
    }
	for (int i = 0; i < this->myWork ->size(); i++){
        //delete(this->myWork->at(i));
        //this->myWork->popAt(i);

    }
    delete(myfield);
    delete(myWork);
}

string Entity::getID(){
    return this->ID;
}

void Entity::setID(string ID){
    this->ID = ID;
}

Field* Entity::fieldAt(int i){
    return this->myfield->at(i);
}

Field* 	Entity::fieldByID(string ID){
    for(int i=0; i<this->myfield->size(); i++){
        if(this->myfield->at(i)->getID()==ID){
            return this->myfield->at(i);
        }
    }
    return NULL;
}

void Entity::addUserField(Field* f){
	this->myfield->push_back(f);
}

void Entity::addIntField(int value){
    this->myfield->push_back(new IntField("StandartInt",value));
}

void Entity::addDoubleField(double value){
    this->myfield->push_back(new DoubleField("StandartDouble",value));
}

void Entity::addStringField(string value){
    this->myfield->push_back(new StringField("StandartString",value));
}

void Entity::addStdField(string value){
    this->myfield->push_back(new Field(value));
}

void Entity::popFieldAt(int i){
	delete(this->myfield->at(i));
	this->myfield->popAt(i);
}

void Entity::popFieldByID(string ID){
    bool stop = false;
    for(int i=0; i<this->myfield->size()&& stop==false; i++){
        if(this->myfield->at(i)->getID()==ID){
            this->popFieldAt(i);
            stop=true;
        }
    }
}

int Entity::fieldCount(){
    return this->myfield->size();
}

bool Entity::isFieldListEmpty(){
    if(this->fieldCount()>0){
        return false;
    }else{
        return true;
    }
}

Work* Entity::workAt(int i){
    return this->myWork->at(i);
}

Work* Entity::workByID(string ID){
    for(int i=0; i<this->myWork->size(); i++){
        if(this->myWork->at(i)->getID()==ID){
            return this->myWork->at(i);
        }
    }
    return NULL;
}

void Entity::addWork(Work* r){
    this->myWork->push_back(r);
}

void Entity::popWorkAt(int i, bool deleteWorkAfterPoping){
    this->myWork->popAt(i);
    if(deleteWorkAfterPoping){ delete(this->myWork->at(i)); }
}

void Entity::popWorkByID(string ID, bool deleteWorkAfterPoping){
    bool stop = false;
    for(int i=0; i<this->myWork->size() && stop==false; i++){
        if(this->myWork->at(i)->getID()==ID){
            if(deleteWorkAfterPoping){ delete(this->myWork->at(i)); }
            this->myWork->popAt(i);
            stop=true;
        }
    }
}

int Entity::workCount(){
    return this->myWork->size();
}

bool Entity::isWorkListEmpty(){
    if(this->workCount()>0){
        return false;
    }else{
        return true;
    }
}

bool Entity::isIDFree(string id){
	for(int i=0; i<this->myfield->size(); i++)
	{
		if (myfield->at(i)->getID() == id)
			return false;
	}
	return true;
}
