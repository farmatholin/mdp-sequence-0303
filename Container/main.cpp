#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "List.h"
#include "Entitie.h"
#include "Work.h"

using namespace std;


int main(int argc, char *argv[])
{

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

	List<Entitie*>* entitieList = new List<Entitie*>();
	entitieList->push_back(new Entitie("123"));
	printf("ADD Entitie %s \n", entitieList->at(0)->getID().c_str());

	entitieList->push_back(new Entitie("GAGA"));
	printf("ADD Entitie %s \n", entitieList->at(1)->getID().c_str());

	entitieList->push_back(new Entitie("ZAZAZA"));
	printf("ADD Entitie %s \n", entitieList->at(2)->getID().c_str());

	entitieList->push_back(new Entitie(" GR GR GR "));
	printf("ADD Entitie %s \n", entitieList->at(3)->getID().c_str());

	printf("\n===================================================\n");
	system("pause");

	return 0;
}
