#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entity.h"
#include <QRect>
#include <QLayout>
#include <QSizePolicy>

#include <QScrollArea>
#include <QLine>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    entities = new QList<Entity*>();

    QScrollArea *scroll = new QScrollArea(this);
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setGeometry(50,50, 600, 400);
    ui->widget->setGeometry(0,0,100,100);
    scroll->setWidget(ui->widget);
    scroll->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntityButton_clicked()
{
    int x = 0, y = 0;

    x = entities->length() > 0 ? entities->last()->geometry().x() + Entity::WIDTH + 20 : 0;

    Entity *entity = new Entity(ui->widget);
    entity->setGeometry(x,0, Entity::WIDTH, Entity::HEIGHT);
    entity->setText(ui->entityNameEdit->text());

    QWidget *line = new QWidget(ui->widget);
    line->setStyleSheet("background-color:black;");
    line->setGeometry(x + (Entity::WIDTH / 2), Entity::HEIGHT, 1, 400);
    line->show();

    ui->entitySelector->addItem(ui->entityNameEdit->text());

    ui->widget->setGeometry(0, 0, x + Entity::WIDTH ,400);
    entity->show();

    entities->append(entity);
}

void MainWindow::on_addTaskButton_clicked()
{
    int x = 0, y = 100;

//    foreach (Entity *entity, entities) {
    for (int i = 0; i < entities->length(); i++) {
        if (entities->at(i)->getText() == ui->entitySelector->currentText()) {
            x = entities->at(i)->geometry().x() + (Entity::WIDTH / 2) - 25;
        }
    }

    QWidget *task = new QWidget(ui->widget);
    task->setGeometry(x, y, 50, 100);
    task->setStyleSheet("background-color:blue;");
    task->show();
}
