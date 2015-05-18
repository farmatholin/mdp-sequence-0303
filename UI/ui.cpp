#include "ui.h"
#include "mainwindow.h"

#include "UI/uientity.h"
#include "UI/uiwork.h"


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

void UI::addWork(Work *work, Entity *fromEntity, Entity *toEntity)
{
    //this->core->add

    UIEntity *fromUIEntity, *toUIEntity;

    QList <UIEntity *> entities = this->baseWidget->findChildren<UIEntity *>();
    for (int i = 0; i < entities.count(); i++) {

        if (entities.at(i)->toolTip() == "uientity") {

            if (entities.at(i)->getEntity() == toEntity) {
                toUIEntity = entities.at(i);
            }

            if (entities.at(i)->getEntity() == fromEntity) {
                fromUIEntity = entities.at(i);
            }
        }
    }

    (new UIWork(this->baseWidget, work, fromUIEntity, toUIEntity))->show();

}

void UI::enable()
{
    this->baseWidget->parentWidget()->setEnabled(true);
}

void UI::disable()
{
    this->baseWidget->setEnabled(false);
}

void UI::drawEntites()
{

}

