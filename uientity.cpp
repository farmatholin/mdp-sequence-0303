#include "uientity.h"
#include <QLabel>
#include <QString>

void UIEntity::show()
{
    QWidget::show();
    this->label->show();
}

void UIEntity::setText(QString text)
{
    this->text = text;
    this->label->setText(text);
}

QString UIEntity::getText()
{
    return this->text;
}
