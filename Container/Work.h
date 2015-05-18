#pragma once
#ifndef WORK_H
#define WORK_H
//=====================================================
#include <string>
#include <iostream>
#include "List.h"
#include "Sequence.h"
#include "Entity.h"

//=====================================================
using namespace std;

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
    Work();
	~Work();

};
template <typename Stream>
Stream & operator>>(Stream &os, Work* w) {
    char* ID;
    char* workTitle;
    double workTime;

    os >> ID;
    os >> workTime;
    os >> workTitle;
    w->setID(string(ID));
    w->setWorkTime(workTime);
    w->setWorkTitle(string(workTitle));

    return os;
}
template <typename Stream>
Stream & operator<<(Stream &os, Work* w) {
    os << w->getID().c_str();
    os << w->getWorkTime();
    os << w->getWorkTitle().c_str();
    os << w->getEntity()->getID().c_str();
    return os;
}
#endif
