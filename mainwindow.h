#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <UI/uientity.h> //todo: remove ?
#include <QList>

#include "UI/ui.h"
#include "Container/Core.h"

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

    void on_updateEntityButton_clicked();

    void on_deleteEntityButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_addSequenceButon_clicked();

    void on_generateReport_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;

    Core *core;
    UI *interace;

    QList<UIEntity *> *entities;
};

#endif // MAINWINDOW_H
