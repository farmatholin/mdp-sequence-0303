#include "mainwindow.h"
#include <QApplication>

#include <stdio.h>
#include <iostream>
#include "Container/List.h"
#include "Container/Entity.h"
#include "Container/Work.h"
#include "Container/Core.h"
#include "Factory/entityfactory.h"

using namespace std;
int main(int argc, char *argv[])
{
    //=================================Testing Core Save
    printf("\n=============================Core SAVE====================================\n");
    EntityFactory* ef = EntityFactory::entityFactory();

    Core* c = new Core();
    Entity* pm = ef->createEntity(TYPE_PROJECT_MANAGER);
    Entity* pr = ef->createEntity(TYPE_PROGRAMMER);
    c->addUserEntity(pm);
    c->addUserEntity(pr);
    c->addWork("StartProject",0,pm);
    c->addWork("Programming",40,pr);
    c->addSequence("Create","Работать",
                   c->getWorkByID("StartProject"),
                   c->getWorkByID("Programming"));
    c->addSequence("Ready","Отдать результат",
                   c->getWorkByID("Programming"),
                   c->getWorkByID("StartProject"));
    c->saveProject("MDP.SE-диаграмма");
    delete(c);

    printf("\n=============================Core SAVE END====================================\n");
    printf("\n=============================Core LOAD====================================\n");
    c = new Core();
    c->loadProject("MDP.SE-диаграмма");

    delete(c);

    printf("\n=============================Core LOAD END====================================\n");

    //End Testing ----------------------------------
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
