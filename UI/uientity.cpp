#include "uientity.h"
#include <QLabel>
#include <QString>

#include <QPushButton>
#include <QLineEdit>

#include "UI/ui.h"
#include "UI/function.h"

#include "Container/StringField.h"
#include "Container/DoubleField.h"

void UIEntity::show()
{
    QWidget::show();
    this->label->show();
}

Entity* UIEntity::getEntity()
{
    return this->entity;
}

void UIEntity::mousePressEvent ( QMouseEvent * event )
{
    this->setStyleSheet("background-color: gray;");

    this->parentWidget()->parentWidget()->setEnabled(false);

    this->active = true;
    this->setToolTip("active");

    (Function::getWidgetByName<QPushButton *>(this, "updateEntityButton"))->setEnabled(true);
//    (Function::getWidgetByName<QPushButton *>(this, "deleteEntityButton"))->setEnabled(true);
    (Function::getWidgetByName<QPushButton *>(this, "addEntityButton"))->setEnabled(false);

    (Function::getWidgetByName<QLineEdit *>(this, "entityName"))->setText(((StringField*)this->entity->fieldByID("title"))->getValue().c_str());
    (Function::getWidgetByName<QLineEdit *>(this, "priceEntity"))->setText(QString::number(((DoubleField*)this->entity->fieldByID("cost"))->getValue()));
}

void UIEntity::setName(string name)
{
    ((StringField* ) entity->fieldByID("title"))->setValue(name);
    this->label->setText(name.c_str());
}

void UIEntity::setRate(double rate)
{
    ((DoubleField* ) entity->fieldByID("cost"))->setValue(rate);
}

bool UIEntity::getActive()
{
    return this->active;
}

void UIEntity::setActive(bool active)
{
    this->active = active;
}
