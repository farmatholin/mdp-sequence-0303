#include "mainwindow.h"
#include <QApplication>

#include <stdio.h>
#include <iostream>
#include "Container/List.h"
#include "Container/Entity.h"
#include "Container/Work.h"

using namespace std;
int main(int argc, char *argv[])
{

    //Testting -------------------------------------------------
    // ListItem Test
    //=================================================
    ListItem<int>* li = new ListItem<int>(5);
    printf("ListItem = %d\n", li->getValue());
    li->setValue(10);
    printf("ListItem = %d\n", li->getValue());
    if (li->getNext() != NULL){
        printf("ListItem = %d\n", li->getNext()->getValue());
    }
    else{
        printf("li->getNext()==NULL\n");
    }
    li->setNext(li);
    if (li->getNext() != NULL){
        printf("ListItem = %d\n", li->getNext()->getValue());
    }
    else{
        printf("li->getNext()==NULL\n");
    }
    delete(li);
    //=================================================
    printf("\n===================================================\n");

    List<int>* list = new List<int>();
    list->push_back(1);
    printf("ADD %d ", list->at(0));
    list->push_back(2);
    printf("ADD %d ", list->at(1));
    list->push_back(3);
    printf("ADD %d ", list->at(2));
    list->push_back(4);
    printf("ADD %d ", list->at(3));
    list->push_back(5);
    printf("ADD %d ", list->at(4));
    list->push_back(6);
    printf("ADD %d ", list->at(5));
    printf("\n");
    for (int i = 0; i<list->size(); i++){
        printf("%d ", list->at(i));
    }
    list->popAt(0);
    list->popAt(4);
    list->popAt(3);
    printf("\n");
    for (int i = 0; i<list->size(); i++){
        printf("%d ", list->at(i));
    }
    delete(list);

    printf("\n===================================================\n");

    printf("\n===================Test Entity======================\n");

    List<Entity*>* entitieList = new List<Entity*>();
    entitieList->push_back(new Entity("123"));
    printf("ADD Entity %s \n", entitieList->at(0)->getID().c_str());

    entitieList->push_back(new Entity("GAGA"));
    printf("ADD Entity %s \n", entitieList->at(1)->getID().c_str());

    entitieList->push_back(new Entity("ZAZAZA"));
    printf("ADD Entity %s \n", entitieList->at(2)->getID().c_str());

    entitieList->push_back(new Entity(" GR GR GR "));
    printf("ADD Entity %s \n", entitieList->at(3)->getID().c_str());

    delete(entitieList);
    printf("\n===================================================\n");

    printf("\n===================Test Sequence and Work======================\n");
    Entity* placeHoler = new Entity("PlaceHolder");
    Entity* pm = new Entity("PM");
    Work* startProcess = new Work("Start Work", 0);
    Work* endProcess = new Work("End Work", 0);
    Work* createDocument = new Work("CreateDocument", 10);
    Sequence* startCreate = new Sequence("startWork", "1 Create Work", startProcess, createDocument);
    Sequence* createEnd = new Sequence("endWork", "2 End Work", createDocument, endProcess);

    startProcess->setEntity(placeHoler);
    startProcess->setSequinceFrom(NULL);
    startProcess->setSequinceTo(startCreate);

    createDocument->setEntity(pm);
    createDocument->setSequinceFrom(startCreate);
    createDocument->setSequinceTo(createEnd);

    endProcess->setEntity(placeHoler);
    endProcess->setSequinceFrom(createEnd);
    endProcess->setSequinceTo(NULL);

    placeHoler->addWork(startProcess);
    placeHoler->addWork(endProcess);

    pm->addWork(createDocument);

    printf("\n===================================================\n");
    delete(pm);
    delete(placeHoler);
    //End Testing ----------------------------------
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
