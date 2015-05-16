#include "qa.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

QA::QA():Entity("qa"+QString::number(id++).toStdString()){
    this->setHourCost(12.5);
    this->myfield->push_back(new StringField("Tittle","Тестировщик - "+ QString::number(id).toStdString()));
}

QA::~QA()
{

}

void QA::setId(int id0){
    id = id0;
}

int QA::id = 0;
