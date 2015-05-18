#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QRect>
#include <QLayout>
#include <QSizePolicy>
#include <QMapIterator>

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
    ui->priceEntity->setText("0");
    ui->entityName->setText("");
}

void MainWindow::on_addTaskButton_clicked()
{
    Entity *toEntity = this->core->entitieById(ui->fromEntitySelector->currentData().toString().toStdString());
    Entity *fromEntity = this->core->entitieById(ui->toEntitySelector->currentData().toString().toStdString());

    if (toEntity == fromEntity) {
        (new QMessageBox(QMessageBox::Warning, "Ошибка", "Назначить задачу на самого себя нельзя!"))->exec();
        return;
    }


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
    List<Entity*> *entities = this->core->getAllEntities();
    for (int i = 0; i < entities->size(); i++) {
        ui->fromEntitySelector->addItem(((StringField* )entities->at(i)->fieldByID("title"))->getValue().c_str(), (QVariant) entities->at(i)->getID().c_str());
        ui->toEntitySelector->addItem(((StringField* )entities->at(i)->fieldByID("title"))->getValue().c_str(), (QVariant) entities->at(i)->getID().c_str());
    }
}
