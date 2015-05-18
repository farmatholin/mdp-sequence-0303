#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QRect>
#include <QLayout>
#include <QSizePolicy>
#include <QMapIterator>

#include <QFileDialog>
#include <QMessageBox>

#include <QScrollArea>
#include <QLine>

#include <iostream>
#include <string>
#include <stdlib.h>

#include "UI/ui.h"
#include "UI/uientity.h"
#include "UI/uiwork.h"
#include "UI/function.h"

#include "Entities/programmer.h"
#include "Factory/entityfactory.h"

#include "Container/DoubleField.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setGeometry(0,0,100,100);

    QScrollArea *scroll = new QScrollArea(this);
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setGeometry(50,50, 600, 400);
    scroll->setWidget(ui->widget);
    scroll->show();

    this->core = new Core();
    this->interace = new UI(this->core, this->ui->widget);

    QMapIterator<int,string> i(EntityFactory::getAvaibleEntities());
    while (i.hasNext()) {
        i.next();
        ui->entitySelector->addItem(i.value().c_str(),(QVariant)i.key());
    }

    //

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntityButton_clicked()
{
    double rate = 0;

    if (0 == ui->priceEntity->text().length() || !(rate = ui->priceEntity->text().toDouble())) {
        (new QMessageBox(QMessageBox::Warning, "Ошибка ввода", "Некорректные данные\n(поле \"Стоимость работы\")"))->exec();
        return;
    }

    Entity *entity = EntityFactory::entityFactory()->createEntity(ui->entitySelector->currentData().toInt());
    entity->addUserField(new DoubleField("cost", rate));

    if (ui->entityName->text().length()) {
        StringField *name = (StringField*) entity->fieldByID("title");
        name->setValue(ui->entityName->text().toStdString());
    }

    this->interace->addEntity(entity);
    this->core->addUserEntity(entity);

    ui->priceEntity->setText("0");
    ui->entityName->setText("");
}

void MainWindow::on_addTaskButton_clicked()
{
    double time;

    if (0 == ui->workTimeEdit->text().length() || !(time = ui->workTimeEdit->text().toDouble())) {
        (new QMessageBox(QMessageBox::Warning, "Ошибка ввода", "Некорректные данные\n(поле \"Продолжительность разработки\")"))->exec();
        return;
    }


    Entity* entity = this->core->entitieById(ui->toEntitySelector->currentData().toString().toStdString());
    string name = ((StringField *) entity->fieldByID("title"))->getValue().c_str();

    Work *work = new Work(name + QString(rand() % 10000).toStdString(), time, ui->workNameEdit->text().toStdString());

    this->interace->addWork(work, entity);
    entity->addWork(work);
    this->core->addUserWork(work);
    work->setEntity(entity);
}

void MainWindow::on_updateEntityButton_clicked()
{
    QList <UIEntity *> entities = ui->widget->findChildren<UIEntity *>();
    for (int i = 0; i < entities.count(); i++) {

        if (entities.at(i)->toolTip() == "active") {

            entities.at(i)->setEnabled(true);
            entities.at(i)->setName(ui->entityName->text().toStdString());
            entities.at(i)->setRate(ui->priceEntity->text().toDouble());
            entities.at(i)->setStyleSheet("background-color: red;");

            entities.at(i)->setToolTip("uientity");
        }
    }

    this->interace->enable();

    (Function::getWidgetByName<QPushButton *>(this, "updateEntityButton"))->setEnabled(false);
    (Function::getWidgetByName<QPushButton *>(this, "deleteEntityButton"))->setEnabled(false);
    (Function::getWidgetByName<QPushButton *>(this, "addEntityButton"))->setEnabled(true);
}

void MainWindow::on_deleteEntityButton_clicked()
{

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->toEntitySelector->clear();
    ui->toWorkSelector->clear();
    ui->fromWorkSelector->clear();

    List<Entity*> *entities = this->core->getAllEntities();
    for (int i = 0; i < entities->size(); i++) {
        ui->toEntitySelector->addItem(((StringField* )entities->at(i)->fieldByID("title"))->getValue().c_str(), (QVariant) entities->at(i)->getID().c_str());
    }

    List<Work *> *works = this->core->getAllWorks();
    for (int i = 0; i < works->size(); i++) {
        ui->toWorkSelector->addItem(works->at(i)->getWorkTitle().c_str(), (QVariant) works->at(i)->getID().c_str());
        ui->fromWorkSelector->addItem(works->at(i)->getWorkTitle().c_str(), (QVariant) works->at(i)->getID().c_str());
    }

}

void MainWindow::on_addSequenceButon_clicked()
{
    Work *fromWork = this->core->getWorkByID(ui->fromWorkSelector->currentData().toString().toStdString());
    Work *toWork = this->core->getWorkByID(ui->toWorkSelector->currentData().toString().toStdString());

    UIWork *fromUIWork, *toUIWork;

    QList <UIWork *> works = ui->widget->findChildren<UIWork *>();
    for (int i = 0; i < works.count(); i++) {

        if (works.at(i)->toolTip() == "uiwork") {

            if (works.at(i)->getWork() == toWork) {
                toUIWork = works.at(i);
            }

            if (works.at(i)->getWork() == fromWork) {
                fromUIWork = works.at(i);
            }
        }
    }
    this->core->addSequence(ui->fromWorkSelector->currentData().toString().toStdString()+ui->toWorkSelector->currentData().toString().toStdString(),
                            "doWOrk",fromWork,toWork);
    QWidget *widget = new QWidget(ui->widget);

    if (fromUIWork->geometry().x() < toUIWork->geometry().x()) {
        widget->setGeometry(fromUIWork->geometry().x() + UIWork::WIDTH , fromUIWork->geometry().y() + (UIWork::HEIGHT / 2), toUIWork->geometry().x() - fromUIWork->geometry().x() - (UIWork::WIDTH / 2), 2);
    } else {
        widget->setGeometry(toUIWork->geometry().x(), fromUIWork->geometry().y() + UIWork::HEIGHT, fromUIWork->geometry().x() - toUIWork->geometry().x(), 2);
    }

    widget->setStyleSheet("background-color: black;");
    widget->show();
}

void MainWindow::on_generateReport_clicked()
{
    ui->reportEdit->setPlainText(this->core->createReview().c_str());
}

void MainWindow::on_saveButton_clicked()
{
    string filename = QFileDialog::getSaveFileName(ui->widget, "Сохранение файла", "~", tr("Sequence diagram (*)")).toStdString();
    this->core->saveProject(filename);
}

void MainWindow::on_loadButton_clicked()
{
    string filename = QFileDialog::getOpenFileName(ui->widget, "Сохранение файла", "~", tr("Sequence diagram (*)")).toStdString();
    this->core->loadProject(filename);

    List <Entity *> *entities = this->core->getAllEntities();
    for (int i = 0; i < entities->size(); i++) {
        this->interace->addEntity(entities->at(i));
    }

    List <Work *> *works = this->core->getAllWorks();
    for (int i = 0; i < works->size(); i++) {
        this->interace->addWork(works->at(i), works->at(i)->getEntity());
    }

    List <Sequence *> *sequences = this->core->getAllSequences();
    for (int i = 0; i < sequences->size(); i++) {

        UIWork *fromUIWork, *toUIWork;

        QList <UIWork *> works = ui->widget->findChildren<UIWork *>();
        for (int j = 0; j < works.count(); j++) {

            if (works.at(j)->toolTip() == "uiwork") {

                if (works.at(j)->getWork() == sequences->at(i)->getWorkTo()) {
                    toUIWork = works.at(j);
                }

                if (works.at(j)->getWork() == sequences->at(i)->getWorkFrom()) {
                    fromUIWork = works.at(j);
                }
            }
        }

        QWidget *widget = new QWidget(ui->widget);

        if (fromUIWork->geometry().x() < toUIWork->geometry().x()) {
            widget->setGeometry(fromUIWork->geometry().x() + (UIWork::WIDTH / 2) , fromUIWork->geometry().y() - 20, toUIWork->geometry().x() - fromUIWork->geometry().x() - (UIWork::WIDTH / 2), 2);
        } else {
            widget->setGeometry(toUIWork->geometry().x()+UIWork::WIDTH, fromUIWork->geometry().y() - 20, fromUIWork->geometry().x() - toUIWork->geometry().x() - (UIWork::WIDTH / 2), 2);
        }

        widget->setStyleSheet("background-color: black;");
        widget->show();
    }
}
