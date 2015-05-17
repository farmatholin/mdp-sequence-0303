#pragma once
#ifndef WORK_H
#define WORK_H
//=====================================================
#include <string>
#include <iostream>
#include "List.h"
#include "Sequence.h"

//=====================================================
using namespace std;

class Entity;
class Sequence;

class Work
{
private:
	string ID;
	double workTime;
    Entity* workEntity;
	Sequence* to;
	Sequence* from;
	
public:
	void setID(string ID);
	string getID();
	double getWorkTime();
	void setWorkTime(double workTime);
    void setEntity(Entity* e);
    Entity* getEntity();
	
	void setSequinceFrom(Sequence* from);
	Sequence* getSequinceFrom();

	void setSequinceTo(Sequence* to);
	Sequence* getSequinceTo();

	explicit Work(string ID, double workTime);
	~Work();
};
#endif
