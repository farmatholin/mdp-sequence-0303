#include "designer.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Designer::Designer():Entity("designer"+QString::number(id++).toStdString()){
    this->myfield->push_back(new StringField("Tittle","Дизайнер - "+ QString::number(id).toStdString()));
}

Designer::~Designer()
{

}

void Designer::setId(int id0){
    id = id0;
}

int Designer::id = 0;