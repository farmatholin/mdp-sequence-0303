#include "programmist.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Programmist::Programmist():Entitie("proger"+QString::number(id++).toStdString()){
    this->setHourCost(15.5);
    this->myfield->push_back(new StringField("Tittle","Программист - "+ QString::number(id).toStdString()));
}

Programmist::~Programmist()
{

}

void Programmist::setId(int id0){
    id = id0;
}

int Programmist::id = 0;
