#include "designer.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Designer::Designer():Entitie("designer"+QString::number(id++).toStdString()){
    this->setHourCost(12.5);
    this->myfield->push_back(new StringField("Tittle","Дизайнер - "+ QString::number(id).toStdString()));
}

Designer::~Designer()
{

}

void Designer::setId(int id0){
    id = id0;
}

int Designer::id = 0;
