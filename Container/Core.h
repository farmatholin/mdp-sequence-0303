#pragma once
#ifndef CORE_H
#define CORE_H
#include <QString>
#include <string>
#include "List.h"
#include "SequenceDiagram.h"
#include "Factory/entityfactory.h"

using namespace std;
class SequenceDiagram;
class Entitie;
class Sequence;

class Core{
private:
    SequenceDiagram* content;
    bool changed;
    int state;//навiщо?
    bool focus;
public:
    void saveProject(string file);
    bool loadProject(string file);
    QString calcMD5(QString fileName);
    void clearSequenceDiagram();
    explicit Core();
    ~Core();
public:
    int getEntitiesCount();
    int getWorksCount();
    int getSequencesCount();
    List<Entity*>* getAllEntities();

public:
    void addEntity(string ID);
    void addUserEntity(Entity* e);
    Entity* entitieAt(int i);
    Entity* entitieById(string ID);
    void popEntityAt(int i);
    void popEntityByID(string ID);
    int getEntityIndexByID(string ID);

public:
    void addWork(string ID, double workTime, Entity* to);
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

#endif // CORE_H
