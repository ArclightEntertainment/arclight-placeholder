#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include "AnimalInputDiag.h"
#include "AnimalListView.h"
#include "AnimalManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    inline void setArr(Animal * arr, int numAn){animalManager->setArr(arr, numAn);}
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleButtonView();
    void handleButtonInput();
    //TEST: void handleButtonTest();
private:
    Ui::MainWindow *ui;
    QPushButton *viewButton;
    QPushButton *inputButton;
    //TEST: QPushButton *testButton;
    AnimalManager *animalManager;
};

#endif // MAINWINDOW_H
