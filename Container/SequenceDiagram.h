#pragma once
#ifndef SEQUENCEDIAGRAM_H
#define SEQUENCEDIAGRAM_H
#include <string>

#include "List.h"
#include "Entitie.h"
#include "Sequence.h"


class Entitie;
class Sequence;
class Work;

class SequenceDiagram{
private:
    string ID;
	List<Entitie*>* entities;
	List<Sequence*>* sequences;
	List<Work*>* works;
public:
    explicit SequenceDiagram(string ID);
    ~SequenceDiagram();

public:
    int getEntitiesCount();
    int getWorksCount();
    int getSequencesCount();

public:
    void addEntitie(string ID);
    void addUserEntitie(Entitie* e);
    Entitie* entitieAt(int i);
    Entitie* entitieById(string ID);
    void popEntitieAt(int i);
    void popEntitieByID(string ID);
    int getEntitieIndexByID(string ID);

public:
    void addWork(string ID, double workTime, Entitie* to);
    void addUserWork(Work* work);
    Work* getWorkAt(int i);
    Work* getWorkByID(string ID);
    void popWorkAt(int i);
    void popWorkByID(string ID);
    int getWorkIndexByID(string ID);

public:
    void addUserSequence(Sequence* s);
    void addSequence(string ID,
                         string name,
                         Work* workFrom,
                         Work* workTo);
    Sequence* sequenceAt(int i);
    Sequence* sequenceByID(string ID);
    void popSequenceAt(int i);
    void popSequenceByID(string ID);
    int getIndexSequenceByID(string ID);
};
#endif
