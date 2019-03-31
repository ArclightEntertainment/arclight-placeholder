#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include "AnimalInputDiag.h"
#include "ClientInputDiag.h"
#include "AnimalListView.h"
#include "AnimalManager.h"
#include "ClientListView.h"
#include "ClientManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    inline void setAnimalArr(Animal * arr, int numAn){animalManager->setArr(arr, numAn);}
    inline void setClientArr(Client * arr, int numCli){clientManager->setArr(arr, numCli);}
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
    AnimalManager *animalManager;
    ClientManager *clientManager;
};

#endif // MAINWINDOW_H
