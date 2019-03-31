#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>


#include "interface/CUACSController.h"
#include "data/DatabaseController.h"
#include "AnimalInputDiag.h"
#include "ClientInputDiag.h"
#include "AnimalListView.h"
#include "ClientListView.h"

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
    void handleButtonAnimalView();
    void handleButtonAnimalInput();
    void handleButtonClientView();
    void handleButtonClientInput();
    //TEST: void handleButtonTest();
private:
    Ui::MainWindow *ui;
    QPushButton *animalInputButton;
    QPushButton *animalViewButton;
    QPushButton *clientInputButton;
    QPushButton *clientViewButton;
    //TEST: QPushButton *testButton;
    CUACSController * mediator;
    Iterator<UAnimal*> * animalIterator;
    Iterator<UClient*> * clientIterator;
};

#endif // MAINWINDOW_H
