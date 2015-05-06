#include "Work.h"

Work::Work(string ID, double workTime){
	this->ID = ID;
	this->workTime = workTime;
}

Work::~Work(){
	delete(to);
	//delete(from);
}

string Work::getID(){
	return this->ID;
}

void Work::setID(string ID){
	this->ID = ID;
}

void Work::setWorkTime(double workTime){
	this->workTime = workTime;
}

void Work::setEntitie(Entitie* e){
	this->workEntitie = e;
}
Entitie* Work::getEntitie(){
	return this->workEntitie;
}

void Work::setSequinceFrom(Sequence* from){
	this->from = from;
}
Sequence* Work::getSequinceFrom(){
	return this->from;
}

void Work::setSequinceTo(Sequence* to){
	this->to = to;
}
Sequence* Work::getSequinceTo(){
	return to;
}