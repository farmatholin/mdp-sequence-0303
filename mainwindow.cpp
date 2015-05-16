#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui/uientity.h"
#include <QRect>
#include <QLayout>
#include <QSizePolicy>

#include <QScrollArea>
#include <QLine>

#include <iostream>

#include "UI/ui.h"

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

    this->interace = new UI(this->core, this->ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntityButton_clicked()
{
    int x = 0, y = 0;

    x = entities->length() > 0 ? entities->last()->geometry().x() + UIEntity::WIDTH + 20 : 0;

    UIEntity *uientity = new UIEntity(ui->widget);
    uientity->setGeometry(x,0, UIEntity::WIDTH, UIEntity::HEIGHT);
    uientity->setText(ui->entityNameEdit->text());

    QWidget *line = new QWidget(ui->widget);
    line->setStyleSheet("background-color:black;");
    line->setGeometry(x + (UIEntity::WIDTH / 2), UIEntity::HEIGHT, 1, 400);
    line->show();

    ui->entitySelector->addItem(ui->entityNameEdit->text());

    ui->widget->setGeometry(0, 0, x + UIEntity::WIDTH ,400);
    uientity->show();

    entities->append(uientity);
}

void MainWindow::on_addTaskButton_clicked()
{
    int x = 0, y = 100;

//    foreach (UIEntity *UIEntity, entities) {
    for (int i = 0; i < entities->length(); i++) {
        if (entities->at(i)->getText() == ui->entitySelector->currentText()) {
            x = entities->at(i)->geometry().x() + (UIEntity::WIDTH / 2) - 25;
        }
    }

    QWidget *task = new QWidget(ui->widget);
    task->setGeometry(x, y, 50, 100);
    task->setStyleSheet("background-color:blue;");
    task->show();
}
