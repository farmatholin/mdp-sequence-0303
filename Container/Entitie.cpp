#include "Entitie.h"

//=====================================================
#include "Field.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "Work.h"
//=====================================================


Entitie::Entitie(string ID){
    this->ID = ID;
    this->myfield = new List<Field*>();
    this->myWork = new List<Work*>();
}

Entitie::~Entitie(){
    for(int i=0; i<this->myfield->size(); i++){
        delete(myfield->at(i));
    }
	for (int i = 0; i < this->myWork ->size(); i++){
        delete(this->myWork->at(i));
        this->myWork->popAt(i);

    }
    delete(myfield);
    delete(myWork);
}

string Entitie::getID(){
    return this->ID;
}

void Entitie::setID(string ID){
    this->ID = ID;
}

Field* Entitie::fieldAt(int i){
    return this->myfield->at(i);
}

Field* 	Entitie::fieldByID(string ID){
    for(int i=0; i<this->myfield->size(); i++){
        if(this->myfield->at(i)->getID()==ID){
            return this->myfield->at(i);
        }
    }
    return NULL;
}

void Entitie::addUserField(Field* f){
	this->myfield->push_back(f);
}

void Entitie::addIntField(int value){
    this->myfield->push_back(new IntField("StandartInt",value));
}

void Entitie::addDoubleField(double value){
    this->myfield->push_back(new DoubleField("StandartDouble",value));
}

void Entitie::addStringField(string value){
    this->myfield->push_back(new StringField("StandartString",value));
}

void Entitie::addStdField(string value){
    this->myfield->push_back(new Field(value));
}

void Entitie::popFieldAt(int i){
	delete(this->myfield->at(i));
	this->myfield->popAt(i);
}

void Entitie::popFieldByID(string ID){
    bool stop = false;
    for(int i=0; i<this->myfield->size()&& stop==false; i++){
        if(this->myfield->at(i)->getID()==ID){
            this->popFieldAt(i);
            stop=true;
        }
    }
}

int Entitie::fieldCount(){
    return this->myfield->size();
}

bool Entitie::isFieldListEmpty(){
    if(this->fieldCount()>0){
        return false;
    }else{
        return true;
    }
}

Work* Entitie::workAt(int i){
    return this->myWork->at(i);
}

Work* Entitie::workByID(string ID){
    for(int i=0; i<this->myWork->size(); i++){
        if(this->myWork->at(i)->getID()==ID){
            return this->myWork->at(i);
        }
    }
    return NULL;
}

void Entitie::addWork(Work* r){
    this->myWork->push_back(r);
}

void Entitie::popWorkAt(int i, bool deleteWorkAfterPoping){
    this->myWork->popAt(i);
    if(deleteWorkAfterPoping){ delete(this->myWork->at(i)); }
}

void Entitie::popWorkByID(string ID, bool deleteWorkAfterPoping){
    bool stop = false;
    for(int i=0; i<this->myWork->size() && stop==false; i++){
        if(this->myWork->at(i)->getID()==ID){
            if(deleteWorkAfterPoping){ delete(this->myWork->at(i)); }
            this->myWork->popAt(i);
            stop=true;
        }
    }
}

int Entitie::workCount(){
    return this->myWork->size();
}

bool Entitie::isWorkListEmpty(){
    if(this->workCount()>0){
        return false;
    }else{
        return true;
    }
}

bool Entitie::isIDFree(string id){
	for(int i=0; i<this->myfield->size(); i++)
	{
		if (myfield->at(i)->getID() == id)
			return false;
	}
	return true;
}
