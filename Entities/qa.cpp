#include "qa.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

QA::QA():Entity("qa"+QString::number(id++).toStdString()){
    this->myfield->push_back(new StringField("title","Тестировщик - "+ QString::number(id-1).toStdString()));
    this->myfield->push_back(new DoubleField("cost",22.5));
}

QA::~QA()
{

}

void QA::setId(int id0){
    id = id0;
}

int QA::id = 0;
