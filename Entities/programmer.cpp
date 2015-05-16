#include "programmer.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Programmer::Programmer():Entity("proger"+QString::number(id++).toStdString()){
    this->setHourCost(15.5);
    this->myfield->push_back(new StringField("Tittle","Программист - "+ QString::number(id).toStdString()));
}

Programmer::~Programmer()
{

}

void Programmer::setId(int id0){
    id = id0;
}

int Programmer::id = 0;
