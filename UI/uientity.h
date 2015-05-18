#ifndef UIENTITY
#define UIENTITY

#include <QWidget>
#include <QLabel>
#include <QList>
#include <QMouseEvent>
#include <QString>

#include "Container/Entity.h"
#include "Container/Field.h"
#include "Container/StringField.h"

class UIEntity : public QWidget {

public:
    static const int WIDTH = 120;
    static const int HEIGHT = 50;

private:
    QLabel *label;
    QString text;
    Entity *entity;
    QWidget * parent;
    bool active;

public:
    UIEntity(QWidget * parent = 0, Entity *entity = 0) : QWidget(parent, 0){

        this->entity = entity;
        this->parent = parent;
        this->active = false;

        this->setToolTip("uientity");

        int x = 0;

        foreach (UIEntity *_entity, parent->findChildren<UIEntity*>()) {

            if (_entity->toolTip() != "uientity") {
                continue;
            }

            x = _entity->geometry().x() > x ? _entity->geometry().x() + this->WIDTH + 10 : x;
        }

        this->setStyleSheet("background-color:red;");
        this->setGeometry(x + 10, 0, this->WIDTH, this->HEIGHT);

        parent->setGeometry(0, 0, x + this->WIDTH + 20 ,400);

        this->label = new QLabel(this);
        this->label->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        this->label->setText(((StringField* ) entity->fieldByID("title"))->getValue().c_str());
        this->label->setGeometry(5, 5, this->WIDTH - 5, this->HEIGHT - 5);

        QWidget *line = new QWidget(parent);
        line->setStyleSheet("background-color:black;");
        line->setGeometry(x + 10 + (this->WIDTH / 2), this->HEIGHT, 1, 400);
        line->show();


    }
    ~UIEntity(){}

    void show();

    Entity* getEntity();

    void setName(string name);
    void setRate(double rate);
    bool getActive();
    void setActive(bool active);

    void mousePressEvent ( QMouseEvent * event );

};

#endif // ENTITY

