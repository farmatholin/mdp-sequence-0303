#include "entity.h"
#include <QLabel>
#include <QString>

void Entity::show()
{
    QWidget::show();
    this->label->show();
}

void Entity::setText(QString text)
{
    this->text = text;
    this->label->setText(text);
}

QString Entity::getText()
{
    return this->text;
}
