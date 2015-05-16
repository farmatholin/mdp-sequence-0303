#include "Core.h"
#include "Entitie.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "qmath.h"
#include <QFile>
#include <QString>
#include <QDataStream>
#include <QIODevice>
#include <QByteArray>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <QCryptographicHash>

Core::Core()
{

}

Core::~Core()
{

}
/*
void Core::saveProject(string file){
    QFile appFile(QString::fromStdString(file));
    Entitie* e;
    Relation* r;
    int i,j,k;
    i=0;
    string type;
    if (appFile.open(QIODevice::WriteOnly)){
        QDataStream inFile(&appFile); // передаем потоку указатель на QIODevice;
        inFile.setVersion(QDataStream::Qt_5_2);
        inFile<<QString::fromStdString("RSL.ER-диаграмма");
        inFile<<this->content->getEntitieCount();
        while (i<this->content->getEntitieCount()){
            e= this->content->entitieAt(i);
            inFile<<(QString::fromStdString(e->getID()));
            j=0;
            inFile<<e->fieldCount();
            while (j<e->fieldCount()){
                if (BASE_FIELD == e->fieldAt(j)->getType()) {
                    type="BASE_T";
                    inFile<<QString::fromStdString(e->fieldAt(j)->getID());
                    inFile<<QString::fromStdString(type);
                }
                if (INT_FIELD == e->fieldAt(j)->getType()) {
                    type="INT_T";
                    inFile<<QString::fromStdString(e->fieldAt(j)->getID());
                    inFile<<QString::fromStdString(type);
                    inFile<<(((IntField*)(e->fieldAt(j)))->getValue());
                }
                if (DOUBLE_FIELD == e->fieldAt(j)->getType()) {
                    type="DOUBLE_T";
                    inFile<<QString::fromStdString(e->fieldAt(j)->getID());
                    inFile<<QString::fromStdString(type);
                    inFile<<(((DoubleField*)(e->fieldAt(j)))->getValue());
                }
                if (STRING_FIELD == e->fieldAt(j)->getType()) {
                    type="STRING_T";
                    inFile<<QString::fromStdString(e->fieldAt(j)->getID());
                    inFile<<QString::fromStdString(type);
                    inFile<<QString::fromStdString(((StringField*)(e->fieldAt(j)))->getValue());
                }
                j++;
            }
            i++;
        }
        k=0;
        inFile<<this->getRelationCount();
        while (k<this->getRelationCount()){
            r=this->content->relationAt(k);
            inFile<<(QString::fromStdString(r->getID()));
            inFile<<(QString::fromStdString(r->getKey()));
            inFile<<(QString::fromStdString(r->getEntL()->getID()));
            inFile<<(QString::fromStdString(r->getEntR()->getID()));
            inFile<<(r->getMulL());
            inFile<<(r->getMulR());
            inFile<<(r->getAbsL());
            inFile<<(r->getAbsR());
            k++;
        }
    }
    appFile.close();
    QString summ=calcMD5(QString::fromStdString(file));
    QFile hash(QString::fromStdString(file+".ks"));
    if (hash.open(QIODevice::WriteOnly)){
        QTextStream myhash(&hash);
        myhash<<summ;
        hash.close();
    }
    //appFile.flush(); // записываем весь буффер в файл;
    return;
}

void Core::newConten(){
    ClearEr();
    this->content = new ERDiagram("Common");
    this->state = 0;
    this->focus = -1;
    this->focusEntitieOrRelation = true;
    this->counter = 0;
    this->counter0 = 0;
    this->counter1 = 0;
    this->weightOfSolution = -1;
    this->solution = NULL;
    this->changed = false;
}

bool Core::loadProject(string file){
    QString a,v,id;
    Entitie* e;
    int count_ent;
    int count_f;
    int count_r;
    int t,j,k;
    QString fId;
    QString key;
    QString entR;
    QString entL;
    bool mulR;
    bool mulL;
    bool absR;
    bool absL;
    Entitie* EntitR;
    Entitie* EntitL;
    int countAll;
    ClearEr();
    this->content = new ERDiagram("Common");
    this->state = 0;
    this->focus = -1;
    this->focusEntitieOrRelation = true;
    this->counter = 0;
    this->counter0 = 0;
    this->counter1 = 0;
    this->weightOfSolution = -1;
    this->solution = NULL;
    this->changed = false;
    QFile readFile(QString::fromStdString(file));
    readFile.open(QFile::ReadOnly);
    QDataStream outFile(&readFile);
    outFile.setVersion(QDataStream::Qt_5_2);
    countAll=0;
    QString summ_f;
    QString summ=calcMD5(QString::fromStdString(file));
    QFile hash(QString::fromStdString(file+".ks"));
    if (hash.open(QIODevice::ReadOnly)){
        QTextStream myhash(&hash);
        myhash>>summ_f;
        hash.close();
    }
    if (summ!=summ_f){
        return false;
    }
    outFile>>a;
    if (a!="RSL.ER-диаграмма"){
        readFile.close();
        return false;
    }
    while (!readFile.atEnd()){
        outFile>>count_ent;
        t=0;
        while (t<count_ent){
            outFile>>a;
            e= new Entitie(a.toStdString());
            outFile>>count_f;
            j=0;
            countAll=countAll+count_f;
            while (j<count_f){
                outFile>>id;
                outFile>>a;
                if (a=="BASE_T") {
                    e->addUserField(new Field(id.toStdString()));
                }else{
                    if (a=="INT_T"){
                        int i;
                        outFile>>i;
                        e->addUserField(new IntField(id.toStdString(),i));
                    }else if (a=="DOUBLE_T"){
                        double d;
                        outFile>>d;
                        e->addUserField(new DoubleField(id.toStdString(),d));
                    }else{
                        if (a=="STRING_T"){
                            QString s;
                            outFile>>s;
                            e->addUserField(new StringField(id.toStdString(),s.toStdString()));
                        }
                    }
                }
                j++;
            }
            this->content->addUserEntitie(e);
            t++;
        }
        k=0;
        outFile>>count_r;
        while (k<count_r){
            outFile>>fId;
            outFile>>key;
            outFile>>entR;
            outFile>>entL;
            outFile>>mulR;
            outFile>>mulL;
            outFile>>absR;
            outFile>>absL;
            EntitR=this->content->entitieByID(entR.toStdString());
            EntitL=this->content->entitieByID(entL.toStdString());
            this->content->addRelation(fId.toStdString(),key.toStdString(), EntitR, EntitL, mulR,mulL,absR,absL);
            k++;
        }
        this->counter=count_ent+1;
        this->counter0=count_r;
        this->counter1=(countAll-count_ent*6);
    }
    readFile.close();
    return true;
}
*/
