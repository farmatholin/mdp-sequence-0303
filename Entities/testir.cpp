#include "testir.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

Testir::Testir():Entity("tester"+QString::number(id++).toStdString()){
    this->setHourCost(12.5);
    this->myfield->push_back(new StringField("Tittle","Тестировщик - "+ QString::number(id).toStdString()));
}

Testir::~Testir()
{

}

void Testir::setId(int id0){
    id = id0;
}

int Testir::id = 0;
