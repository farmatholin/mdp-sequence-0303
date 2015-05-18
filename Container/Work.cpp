#include "Work.h"

Work::Work(string ID, double workTime, string workTitle){
	this->ID = ID;
	this->workTime = workTime;
    this->workTitle = workTitle;
    this->workEntity = NULL;
}

Work::Work(){
    this->ID = "";
    this->workTime = 0;
    this->workTitle = "";
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

string Work::getWorkTitle(){
    return this->workTitle;
}

void Work::setWorkTitle(string workTitle){
    this->workTitle = workTitle;
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
