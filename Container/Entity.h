#pragma once
#ifndef ENTITY_H
#define ENTITY_H

//=====================================================
#include <string>
#include "List.h"
//=====================================================
using namespace std;

class Work;
class Field;

class Entity {
protected:
    string ID;
    List<Field*>* myfield;
    List<Work*>* myWork;

public:
    explicit Entity(string ID);
    virtual ~Entity();
	
public:
    string getID();
    void setID(string ID);
	
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
