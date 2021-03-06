#pragma once
#ifndef SEQUENCEDIAGRAM_H
#define SEQUENCEDIAGRAM_H
#include <string>

#include "List.h"
#include "Entity.h"
#include "Sequence.h"
#include "Work.h"


class Entity;
class Sequence;
class Work;

class SequenceDiagram{
private:
    string ID;
    List<Entity*>* entities;
    List<Work*>* works;
	List<Sequence*>* sequences;

public:
    explicit SequenceDiagram(string ID);
    ~SequenceDiagram();

public:
    int getEntitiesCount();
    int getWorksCount();
    int getSequencesCount();
    List<Entity*>* getAllEntities();
    List<Work*>* getAllWorks();
    List<Sequence*>* getAllSequences();

public:
    void addEntity(string ID);
    void addUserEntity(Entity* e);
    Entity* entitieAt(int i);
    Entity* entitieById(string ID);
    void popEntityAt(int i);
    void popEntityByID(string ID);
    int getEntityIndexByID(string ID);

public:
    void addWork(string ID, double workTime, string workTitle, Entity* to);
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
