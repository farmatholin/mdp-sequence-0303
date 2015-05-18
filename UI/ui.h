#ifndef UI_H
#define UI_H

#include <QWidget>

#include "Container/Core.h"
#include "Container/Entity.h"
#include "Container/Work.h"

class UI
{
private:
//    MainWindow ui;
    Core *core;
    QWidget *baseWidget;

public:
    UI(Core *core, QWidget *baseWidget);
    ~UI();

    void addEntity(Entity *entity);
    void addWork(Work *work, Entity *toEntity);

    void enable();
    void disable();

    void drawEntites();
    void drawWorks();

    void reDrawAll();

//    void static editEntity(UIEntity *entity);
};

#endif // UI_H
