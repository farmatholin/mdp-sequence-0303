#include "projectmanager.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

ProjectManager::ProjectManager():Entitie("PM"+QString::number(id++).toStdString()){
    this->setHourCost(25.5);
    this->myfield->push_back(new StringField("Tittle","PM - "+ QString::number(id).toStdString()));
}

ProjectManager::~ProjectManager(){
}

void ProjectManager::setId(int id0){
    id=id0;
}

int ProjectManager::id = 0;
