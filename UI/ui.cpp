#include "ui.h"
#include "mainwindow.h"

#include "UI/uientity.h"


UI::UI(Core *core, QWidget *baseWidget)
{
    this->core = core;
    this->baseWidget = baseWidget;
}

void UI::addEntity(Entity *entity)
{
    this->core->addUserEntity(entity);

    UIEntity *uientity = new UIEntity(this->baseWidget, entity);
    uientity->show();

}

void UI::drawEntites()
{

}

