#include "Core.h"
#include "Entity.h"
#include "IntField.h"
#include "DoubleField.h"
#include "StringField.h"
#include "qmath.h"
#include <ostream>
#include <sstream>
#include <QFile>
#include <QString>
#include <QDataStream>
#include <QIODevice>
#include <QByteArray>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>
#include <QCryptographicHash>

Core::Core(){
    this->content = new SequenceDiagram("Common");
    this->state = 0;
}

Core::~Core(){
    delete(this->content);
}

int Core::getEntitiesCount(){
    return this->content->getEntitiesCount();
}

int Core::getWorksCount(){
    return this->content->getWorksCount();
}

int Core::getSequencesCount(){
    return this->content->getSequencesCount();
}

List<Entity*>* Core::getAllEntities(){
    return this->content->getAllEntities();
}

void Core::addEntity(string ID){
    this->content->addEntity(ID);
}

void Core::addUserEntity(Entity *e){
    this->content->addUserEntity(e);
}

Entity* Core::entitieAt(int i){
    return this->content->entitieAt(i);
}

Entity* Core::entitieById(string ID){
    return this->content->entitieById(ID);
}

void Core::popEntityAt(int i){
    this->content->popSequenceAt(i);
}

void Core::popEntityByID(string ID){
    this->content->popEntityByID(ID);
}

int Core::getEntityIndexByID(string ID){
    return this->content->getEntityIndexByID(ID);
}

void Core::addWork(string ID, double workTime, string workTitle, Entity *to){
   this->content->addWork(ID, workTime, workTitle, to);
}

void Core::addUserWork(Work *work){
    this->content->addUserWork(work);
}

Work* Core::getWorkAt(int i){
    return this->content->getWorkAt(i);
}

Work* Core::getWorkByID(string ID){
    return this->content->getWorkByID(ID);
}

void Core::popWorkAt(int i){
    this->content->popWorkAt(i);
}

void Core::popWorkByID(string ID){
    this->content->popWorkByID(ID);
}

int Core::getWorkIndexByID(string ID){
    return this->content->getWorkIndexByID(ID);
}

void Core::addUserSequence(Sequence* s){
    this->content->addUserSequence(s);
}

void Core::addSequence(string ID, string name, Work *workFrom, Work *workTo){
   this->content->addSequence(ID,name,workFrom,workTo);
}

Sequence *Core::sequenceAt(int i){
    return this->content->sequenceAt(i);
}

Sequence *Core::sequenceByID(string ID){
    return this->content->sequenceByID(ID);
}

void Core::popSequenceAt(int i){
    this->content->popSequenceAt(i);
}

void Core::popSequenceByID(string ID){
    this->content->popSequenceByID(ID);
}

int Core::getIndexSequenceByID(string ID){
    return this->content->getIndexSequenceByID(ID);
}

string Core::doubleToString(double val){
    ostringstream ost;
    ost << val;
    return ost.str();
}

string Core::createReview(){
    string review = "";
    if(this->getEntitiesCount() == 0)
    {
        return "Нет работников";
    }
    for(int i=0;i<this->getEntitiesCount();++i){
        review +="Работник " +((StringField*)this->entitieAt(i)->fieldByID("title"))->getValue() + "\n";
        review += "Стоимость работы "+  this->doubleToString(((DoubleField*)this->entitieAt(i)->fieldByID("cost"))->getValue()) + "\n";
    }
    if(this->getWorksCount() == 0){
        return review += "\n Нету работ \n";
    }
    double fullCost = 0;
    for(int i=0;i<this->getEntitiesCount();++i){
        Entity* e = this->entitieAt(i);
        review +="Работник " +((StringField*)e->fieldByID("title"))->getValue() + "\n";
        review += "Работа(ты):\n";
        if(e->workCount() == 0){
            review += "Нету работы\n";
        }else {
            double workCost = ((DoubleField*)e->fieldByID("cost"))->getValue();
            double getForAllWorks = 0;
            for(int j = 0; j< e->workCount(); ++j){
                Work* w = e->workAt(j);
                review += w->getWorkTitle() +"\n";
                review += "Время "+ this->doubleToString(w->getWorkTime())+ "ч ";
                review += "Стоимость "+ this->doubleToString(workCost) +"\n";
                review += "Стоимость исполнения: " + this->doubleToString(workCost*w->getWorkTime())+"\n";
                getForAllWorks += workCost*w->getWorkTime();
            }
            review += ((StringField*)e->fieldByID("title"))->getValue() + " получит: "+this->doubleToString(getForAllWorks)+"\n";
            fullCost += getForAllWorks;
        }

    }
    review += "Общая сумма исполнения = " +this->doubleToString(fullCost)+ "\n";
    double fullWorkTime = 0;
    for(int i = 0; i<this->getWorksCount();++i){
        fullWorkTime += this->getWorkAt(i)->getWorkTime();
    }
    review += "Время полного выполнения "+ this->doubleToString(fullWorkTime)+"ч.\n";
    review += "Среднее время выполнения работы "+ this->doubleToString(fullWorkTime/getWorksCount())+"ч.\n";
    return review;
}

bool Core::loadProject(string file){
        QString a,v,id;
        Entity* e;
        Work* w;
        Sequence* s;
        int count_ent;
        int count_work;
        int count_s;
        int count_f;
        int t,j,k;
        QString fId;
        QString key;
        int countAll;
        this->clearSequenceDiagram();
        this->content = new SequenceDiagram("Common");
        this->state = 0;
        this->focus = -1;

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
        if (a!="MDP.SE-диаграмма"){
            readFile.close();
            return false;
        }
        while (!readFile.atEnd()){
            outFile>>count_ent;
            t=0;
            while (t<count_ent){
                outFile>>a;
                e= new Entity(a.toStdString());
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
                this->content->addUserEntity(e);
                t++;
            }
            k=0;
            outFile>>count_work;
            while(k<count_work){
                QString ID;
                double workTime;
                QString workTitle;
                QString entityID;
                outFile>>ID;
                outFile>>workTime;
                outFile>>workTitle;
                outFile>>entityID;
                Entity* we = this->content->entitieById(entityID.toStdString());
                this->addWork(ID.toStdString(), workTime, workTitle.toStdString(), we);
                k++;
            }
            k=0;
            outFile>>count_s;
            while(k<count_s){
                QString ID;
                QString title;
                QString workTo;
                QString workFrom;
                outFile>>ID;
                outFile>>title;
                outFile>>workTo;
                outFile>>workFrom;
                Work* wt = this->content->getWorkByID(workTo.toStdString());
                Work* wf = this->content->getWorkByID(workFrom.toStdString());
                this->content->addSequence(ID.toStdString(),title.toStdString(),wf,wt);
                k++;
            }
        }
        readFile.close();
        return true;

    }
//Сериализация
    void Core::saveProject(string file){
        QFile appFile(QString::fromStdString(file));
        Entity* e;
        Work* w;
        Sequence* s;
        int i,j,k;
        i=0;
        string type;
        if (appFile.open(QIODevice::WriteOnly)){
            QDataStream inFile(&appFile); // передаем потоку указатель на QIODevice;
            inFile.setVersion(QDataStream::Qt_5_2);
            inFile<<QString::fromStdString("MDP.SE-диаграмма");
            inFile<<this->content->getEntitiesCount();
            while (i<this->content->getEntitiesCount()){
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
            i=0;
            inFile<<this->content->getWorksCount();
            while (i<this->content->getWorksCount()){
                w= this->content->getWorkAt(i);
                inFile<<(QString::fromStdString(w->getID()));
                inFile<<(w->getWorkTime());
                inFile<<(QString::fromStdString(w->getWorkTitle()));
                inFile<<(QString::fromStdString(w->getEntity()->getID()));
                i++;
            }
            i=0;
            inFile<<this->content->getSequencesCount();
            while (i<this->content->getSequencesCount()){
                s= this->content->sequenceAt(i);
                inFile<<(QString::fromStdString(s->getID()));
                inFile<<(QString::fromStdString(s->getSequenceName()));
                inFile<<(QString::fromStdString(s->getWorkFrom()->getID()));
                inFile<<(QString::fromStdString(s->getWorkTo()->getID()));
                i++;
            }
        }
        appFile.close();
        QString summ = calcMD5(QString::fromStdString(file));
        QFile hash(QString::fromStdString(file+".ks"));
        if (hash.open(QIODevice::WriteOnly)){
            QTextStream myhash(&hash);
            myhash<<summ;
            hash.close();
        }
        //appFile.flush(); // записываем весь буффер в файл;
        return;
    }

    void Core::clearSequenceDiagram(){
        delete(this->content);
    }

    QString Core::calcMD5(QString fileName){
        QString result;
        QByteArray data;
        QCryptographicHash cryp(QCryptographicHash::Md5);
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly) ){
            data = file.readAll();
            cryp.addData(data);
            result = cryp.result().toHex().data();
            file.close();
        }

    return result;
    }
