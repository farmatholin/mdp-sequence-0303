#pragma once
#ifndef SEQUENCEDIAGRAMM_H
#define SEQUENCEDIAGRAMM_H
#include <string>

#include "List.h"
#include "Entitie.h"
#include "Sequence.h"


class Entitie;
class Sequence;
class Work;

class SequenceDiagramm{
private:
    string ID;
	List<Entitie*>* entities;
	List<Sequence*>* sequences;
	List<Work*>* works;
public:
    explicit SequenceDiagramm(string ID);
	~SequenceDiagramm();

public:
    int getEntititesCount();
    int getWorksCount();
    int getSequenceCount();

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
    void addSequence(string ID);
    void addUserSequence(string ID,
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
