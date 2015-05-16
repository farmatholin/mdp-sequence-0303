#include "Sequence.h"


Sequence::Sequence(string ID, string sequenceName, Work* from, Work* to){
	this->ID = ID;
	this->sequenceName = sequenceName;
	this->fromWork = from;
	this->toWork = to;
}


Sequence::~Sequence(){
	//delete(toWork);
	//delete(fromWork);
}

void Sequence::setID(string ID){
	this->ID = ID;
}
string Sequence::getID(){
	return this->ID;
}

void Sequence::setWorkFrom(Work* from){
	this->fromWork = from;
}
Work* Sequence::getWorkFrom(){
	return this->fromWork;
}

void Sequence::setWorkTo(Work* to){
	this->toWork = to;
}
Work* Sequence::getWorkTo(){
	return this->toWork;
}

void Sequence::setSequenceName(string sequenceName){
	this->sequenceName = sequenceName;
}
string Sequence::getSequenceName(){
	return this->sequenceName;
}
