#pragma once
#ifndef SEQUENCEDIAGRAMM_H
#define SEQUENCEDIAGRAMM_H

#include "List.h"
#include "Entitie.h"
#include "Sequence.h"

class Entitie;
class Sequence;
class Work;

class SequenceDiagramm{
private:
	List<Entitie*>* entities;
	List<Sequence*>* sequences;
	List<Work*>* works;
public:
	SequenceDiagramm();
	~SequenceDiagramm();
};
#endif