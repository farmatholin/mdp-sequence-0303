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
    string workTitle;
    Entity* workEntity;
	Sequence* to;
	Sequence* from;
	
public:
	void setID(string ID);
	string getID();
	double getWorkTime();
    string getWorkTitle();
    void setWorkTitle(string workTitle);
	void setWorkTime(double workTime);
    void setEntity(Entity* e);
    Entity* getEntity();
	
	void setSequinceFrom(Sequence* from);
	Sequence* getSequinceFrom();

	void setSequinceTo(Sequence* to);
	Sequence* getSequinceTo();

    explicit Work(string ID, double workTime, string worktTitle);
	~Work();
};
#endif
