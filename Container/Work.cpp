#include "Work.h"

Work::Work(string ID, double workTime){
	this->ID = ID;
	this->workTime = workTime;
}

Work::~Work(){
	delete(workEntity);
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

void Work::setEntity(Entity* e){
	this->workEntity = e;
}
Entity* Work::getEntity(){
	return this->workEntity;
}