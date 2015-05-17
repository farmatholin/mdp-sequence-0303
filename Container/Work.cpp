#include "Work.h"

Work::Work(string ID, double workTime){
	this->ID = ID;
	this->workTime = workTime;
    this->workEntity = NULL;
}

Work::~Work(){
    //delete(to);
	//delete(from);
}

string Work::getID(){
    return this->ID;
}

double Work::getWorkTime(){
    return this->workTime;
}

void Work::setID(string ID){
	this->ID = ID;
}

void Work::setWorkTime(double workTime){
	this->workTime = workTime;
}

void Work::setEntity(Entity* e){
	this->workEntity = e;
}
Entity* Work::getEntity(){
	return this->workEntity;
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
