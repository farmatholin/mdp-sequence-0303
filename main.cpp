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
    Entity* qa = ef->createEntity(TYPE_QA);
    c->addUserEntity(pm);
    c->addUserEntity(pr);
    c->addUserEntity(qa);
    c->addWork("StartProject",20, "Разработка",pm);
    c->addWork("Programming",40,"Программирование",pr);
    c->addWork("CheckResults",2,"Доработка",pr);
    c->addWork("Testing",20,"Тестирование",qa);
    c->addSequence("Create","Дать задачу",
                   c->getWorkByID("StartProject"),
                   c->getWorkByID("Programming"));
    c->addSequence("Testing", "Отдать на тестирование",
                    c->getWorkByID("Programming"),
                    c->getWorkByID("Testing"));
    c->addSequence("ReadyTesting","Отдать результат Тестирования",
                   c->getWorkByID("Testing"),
                   c->getWorkByID("CheckResults"));
    c->addSequence("Ready","Отдать результат",
                   c->getWorkByID("CheckResults"),
                   c->getWorkByID("StartProject"));
    string review = c->createReview();
    cout << review;
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
