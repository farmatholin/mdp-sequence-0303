#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include "Work.h"
using namespace std;
class Work;

class Sequence{
private:
	string ID;
	string sequenceName;
	Work* fromWork;
	Work* toWork;

public:
	explicit Sequence(string ID, string sequenceName, Work* from, Work* to);
	~Sequence();

	void setID(string ID);
	string getID();
	
	void setWorkFrom(Work* from);
	Work* getWorkFrom();
	
	void setWorkTo(Work* to);
	Work* getWorkTo();

	void setSequenceName(string sequenceName);
	string getSequenceName();
	
};
#endif

