#include "programmer.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Programmer::Programmer():Entity("proger"+QString::number(id++).toStdString()){
    this->myfield->push_back(new StringField("title","Программист - "+ QString::number(id).toStdString()));
    this->myfield->push_back(new DoubleField("cost",25.0));
}

Programmer::~Programmer()
{

}

void Programmer::setId(int id0){
    id = id0;
}

int Programmer::id = 0;
