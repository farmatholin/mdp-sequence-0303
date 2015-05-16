#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <entity.h>

#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_addEntityButton_clicked();

    void on_addTaskButton_clicked();

private:
    Ui::MainWindow *ui;

    QList<Entity *> *entities;

};

#endif // MAINWINDOW_H
