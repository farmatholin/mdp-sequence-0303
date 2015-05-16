#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "UI/uientity.h"
#include <QRect>
#include <QLayout>
#include <QSizePolicy>
#include <QMapIterator>

#include <QScrollArea>
#include <QLine>

#include <iostream>

#include "UI/ui.h"

#include "Entities/programmer.h"
#include "Factory/entityfactory.h"

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

//    foreach (Entity *_entity, core->getAllEntities()) {
//        ui->entitySelector->addItem(_entity->getID());
//    }

    QMapIterator<int,string> i(EntityFactory::getAvaibleEntities());
    while (i.hasNext()) {
        i.next();
        QVariant qv = i.key();
        ui->entitySelector->addItem(i.value().c_str(),(QVariant)i.key());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntityButton_clicked()
{
    Programmer *p = new Programmer();
    this->interace->addEntity(p);
}

void MainWindow::on_addTaskButton_clicked()
{
//    int x = 0, y = 100;

////    foreach (UIEntity *UIEntity, entities) {
//    for (int i = 0; i < entities->length(); i++) {
//        if (entities->at(i)->getText() == ui->entitySelector->currentText()) {
//            x = entities->at(i)->geometry().x() + (UIEntity::WIDTH / 2) - 25;
//        }
//    }

//    QWidget *task = new QWidget(ui->widget);
//    task->setGeometry(x, y, 50, 100);
//    task->setStyleSheet("background-color:blue;");
//    task->show();
}
