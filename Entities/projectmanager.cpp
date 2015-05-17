#include "projectmanager.h"
#include "Container/DoubleField.h"
#include "Container/IntField.h"
#include "Container/StringField.h"
#include <QString>

ProjectManager::ProjectManager():Entity("PM"+QString::number(id++).toStdString()){
    this->myfield->push_back(new StringField("title","PM - "+ QString::number(id-1).toStdString()));
    this->myfield->push_back(new DoubleField("cost", 40));
}

ProjectManager::~ProjectManager(){
}

void ProjectManager::setId(int id0){
    id=id0;
}

int ProjectManager::id = 0;
