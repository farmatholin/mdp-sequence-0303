#ifndef UI_H
#define UI_H

#include <QWidget>

#include "Container/Core.h"
#include "Container/Entity.h"

class UI
{
private:
//    MainWindow *ui;
    Core *core;
    QWidget *baseWidget;

public:
    UI(Core *core, QWidget *baseWidget);
    ~UI();

    void addEntity(Entity *entity);

    void drawEntites();
    void drawWorks();

    void reDrawAll();
};

#endif // UI_H
