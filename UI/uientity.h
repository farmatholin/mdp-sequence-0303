#ifndef UIENTITY
#define UIENTITY

#include <QWidget>
#include <QLabel>
#include <QList>
#include <QMouseEvent>
#include <QString>

#include "Container/Entity.h"

class UIEntity : public QWidget {

public:
    static const int WIDTH = 100;
    static const int HEIGHT = 50;

private:
    QLabel *label;
    QString text;

public:
    UIEntity(QWidget * parent = 0, Entity *entity = 0) : QWidget(parent, 0){

        int x = 0;

        foreach (UIEntity *_entity, parent->findChildren<UIEntity*>()) {
            x = _entity->geometry().x() > x ? _entity->geometry().x() + this->WIDTH + 10 : x;
        }

        this->setGeometry(x + 10, 0, this->WIDTH, this->HEIGHT);

        parent->setGeometry(0, 0, x + this->WIDTH + 20 ,400);

        this->label = new QLabel(this);
        this->label->setText(entity->getID().c_str());
        this->label->setGeometry(5, 5, this->WIDTH - 5, this->HEIGHT - 5);

        this->setStyleSheet("background-color:red;");
    };
    ~UIEntity(){};

    void show();
    void setText(QString text);
    QString getText();
};

#endif // ENTITY

