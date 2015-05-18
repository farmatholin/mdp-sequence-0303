#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>

class Function
{
public:
    Function();

    template <typename T>
    static T getWidgetByName(QWidget *widget, QString name){
        QWidget *parent = widget;

        while (parent->parentWidget()) {
            parent = parent->parentWidget();
        }

        return parent->findChild<T>(name);
    }

};

#endif // FUNCTION_H
