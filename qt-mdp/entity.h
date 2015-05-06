#ifndef ENTITY
#define ENTITY

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QString>

class Entity : public QWidget {

public:
    static const int WIDTH = 100;
    static const int HEIGHT = 50;

private:
    QLabel *label;
    QString text;

public:
    Entity(QWidget * parent = 0, Qt::WindowFlags f = 0) : QWidget(parent, f){
        this->label = new QLabel(this);
        this->label->setText("example");
        this->label->setGeometry(5, 5, this->WIDTH - 5, this->HEIGHT - 5);

        this->setStyleSheet("background-color:red;");
    };
    ~Entity(){};

    void show();
    void setText(QString text);
    QString getText();
};

#endif // ENTITY

