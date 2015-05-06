#pragma once
#ifndef ENTITIE_H
#define ENTITIE_H

//=====================================================
#include <string>
#include "List.h"
//=====================================================
using namespace std;

class Work;
class Field;

class Entitie {
protected:
    string ID;
	double hourCost;
    List<Field*>* myfield;
    List<Work*>* myWork;

public:
    explicit Entitie(string ID);
    virtual ~Entitie();
	
public:
    string getID();
    void setID(string ID);
	double getHourCost();
	void setHourCost(double hourCost);
	
public:
    Field* 	fieldAt(int i);
    Field* 	fieldByID(string ID);
    void    addUserField(Field* f);
    void    addIntField(int value);
    void    addDoubleField(double value);
    void    addStringField(string value);
    void    addStdField(string value);
    void    popFieldAt(int i);
    void    popFieldByID(string ID);
    int     fieldCount();
    bool    isFieldListEmpty();
	
public:	
	Work* 	workAt(int i);
    Work* 	workByID(string ID);
	void    addWork(Work* r);          
    void    popWorkAt(int i, bool deleteWorkAfterPoping);
    void    popWorkByID(string ID, bool deleteWorkAfterPoping);
    int     workCount();
    bool    isWorkListEmpty();
	bool    isIDFree(string id);
};

#endif // ENTITIE_H
