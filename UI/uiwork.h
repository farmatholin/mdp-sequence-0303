#ifndef UIWORK_H
#define UIWORK_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include <QMouseEvent>
#include <QString>

#include "Container/Entity.h"
#include "Container/Work.h"
#include "Container/Field.h"
#include "Container/StringField.h"

#include "UI/uientity.h"

class UIWork : public QWidget
{
public:
    static const int WIDTH = 30;
    static const int HEIGHT = 80;

private:
    Work *work;
    UIEntity *fromEntity, *toEntity;

public:
    UIWork(QWidget * parent = 0, Work *work = 0, UIEntity *fromEntity = 0, UIEntity * toEntity = 0) : QWidget(parent, 0){
        this->work = work;
        this->fromEntity = fromEntity;
        this->toEntity = toEntity;

        this->setToolTip("uiwork");

        int y = UIEntity::HEIGHT + 20;

        foreach (UIWork *_entity, parent->findChildren<UIWork*>()) {

            if (_entity->toolTip() != "uiwork") {
                continue;
            }

            y = _entity->geometry().y() > y ? _entity->geometry().y() + this->HEIGHT + 15 : y;
        }

        this->setStyleSheet("backgroung-color: blue;");
        this->setGeometry(fromEntity->geometry().x() - (this->WIDTH / 2), y, this->WIDTH, this->HEIGHT);

        this->show();
    }
};

#endif // UIWORK_H
