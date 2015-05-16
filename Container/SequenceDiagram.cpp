#include "SequenceDiagram.h"
#include "Entitie.h"
#include "Work.h"
#include "Sequence.h"

SequenceDiagram::SequenceDiagram(string ID){
    this->ID = ID;
    this->entities = new List<Entitie*>();
    this->works = new List<Work*>();
    this->sequences = new List<Sequence*>();
}


SequenceDiagram::~SequenceDiagram(){
    for(int i = 0; i < this->sequences->size(); ++i){
        delete(this->sequences->at(i));
    }
    for(int i = 0; i < this->works->size(); ++i){
        delete(this->works->at(i));
    }
    for(int i = 0; i < this->entities->size(); ++i){
        delete(this->entities->at(i));
    }
    delete(this->entities);
    delete(this->works);
    delete(this->sequences);
}

int SequenceDiagram::getEntitiesCount(){
    return this->entities->size();
}

int SequenceDiagram::getWorksCount(){
    return this->works->size();
}

int SequenceDiagram::getSequencesCount(){
    return this->sequences->size();
}

void SequenceDiagram::addEntitie(string ID){
    this->entities->push_back(new Entitie(ID));
}

void SequenceDiagram::addUserEntitie(Entitie *e){
    this->entities->push_back(e);
}

Entitie *SequenceDiagram::entitieAt(int i){
    return this->entities->at(i);
}

Entitie *SequenceDiagram::entitieById(string ID){
    for(int i = 0; i < this->entities->size(); ++i){
        if(this->entities->at(i)->getID() == ID){
            return this->entities->at(i);
        }
    }
    return NULL;
}

void SequenceDiagram::popEntitieAt(int i){

    Entitie* e = this->entitieAt(i);
    List<Work*>* del = new List<Work*>();

    for(int j = 0; j < e->workCount(); ++j){
        del->push_back(e->workAt(j));
        this->popWorkByID(e->workAt(j)->getID());
    }

    for(int j=0; j < del->size(); ++j){
        delete(del->at(j));
    }

    delete(del);
    delete(this->entities->at(i));

    this->entities->popAt(i);
}

void SequenceDiagram::popEntitieByID(string ID){
    for (int i=0; i<this->entities->size(); i++){
        if(this->entities->at(i)->getID()==ID){
            this->popEntitieAt(i);
        }
    }
}

int SequenceDiagram::getEntitieIndexByID(string ID){
    for(int i = 0; i< this->getEntitiesCount(); ++i){
        if(this->entitieAt(i)->getID()==ID){
            return i;
        }
    }
    return 0;
}

void SequenceDiagram::addWork(string ID, double workTime, Entitie *to){
    Work* w = new Work(ID, workTime);
    w->setEntitie(to);
    to->addWork(w);

    this->works->push_back(w);
}

void SequenceDiagram::addUserWork(Work *work){
    this->works->push_back(work);
}

Work *SequenceDiagram::getWorkAt(int i){
    return this->works->at(i);
}

Work *SequenceDiagram::getWorkByID(string ID){
    for(int i = 0; i < this->works->size(); ++i){
        if(this->works->at(i)->getID() == ID){
            return this->works->at(i);
        }
    }
    return NULL;
}

void SequenceDiagram::popWorkAt(int i){
    this->popWorkByID(this->works->at(i)->getID());
}

void SequenceDiagram::popWorkByID(string ID){
    for(int i = 0; i < this->works->size(); ++i){
        if(this->works->at(i)->getID() == ID){
            Work* w = this->works->at(i);
            w->getEntitie()->popWorkByID(w->getID());
            this->popSequenceByID(w->getSequinceFrom());
            this->popSequenceByID(w->getSequinceTo());
            delete(w);
        }
    }
}

int SequenceDiagram::getWorkIndexByID(string ID){
    for(int i = 0; i < this->works->size(); ++i){
        if(this->works->at(i)->getID() == ID){
            return i;
        }
    }
    return 0;
}

void SequenceDiagram::addSequence(Sequence* s){
    this->sequences->push_back(s);
}

void SequenceDiagram::addUserSequence(string ID, string name, Work *workFrom, Work *workTo){
    Sequence* s = new Sequence(ID,name,workTo,workFrom);
    workTo->setSequinceTo(s);
    workFrom->setSequinceFrom(s);
    this->sequences->push_back(s);
}

Sequence *SequenceDiagram::sequenceAt(int i){
    return this->sequences->at(i);
}

Sequence *SequenceDiagram::sequenceByID(string ID){
    for(int i=0; i < this->sequences->size(); ++i){
        if(this->sequences->at(i)->getID() == ID){
            return this->sequences->at(i);
        }
    }
    return NULL;
}

void SequenceDiagram::popSequenceAt(int i){
    this->popSequenceByID(this->sequences->at(i)->getID());
}

void SequenceDiagram::popSequenceByID(string ID){
    for(int i=0; i < this->sequences->size(); ++i){
        if(this->sequences->at(i)->getID() == ID){
            Sequence* s = this->sequences->at(i);
            s->getWorkFrom()->setSequinceFrom(NULL);
            s->getWorkTo()->setSequinceTo(NULL);
            this->sequences->popAt(i);
            delete(s);
        }
    }
}

int SequenceDiagram::getIndexSequenceByID(string ID){
    for(int i=0; i < this->sequences->size(); ++i){
        if(this->sequences->at(i)->getID() == ID){
            return i;
        }
    }
    return 0;
}