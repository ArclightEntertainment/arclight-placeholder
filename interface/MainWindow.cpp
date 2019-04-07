#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "Tests.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect pointers to buttons
    animalViewButton = ui->animalViewButton;
    animalInputButton = ui->animalInputButton;
    clientViewButton = ui->clientViewButton;
    clientInputButton = ui->clientInputButton;

    //connect buttons to slots
    connect(animalInputButton, SIGNAL(released()), this,SLOT(handleButtonAnimalInput()));
    connect(animalViewButton, SIGNAL(released()), this,SLOT(handleButtonAnimalView()));
    connect(clientInputButton, SIGNAL(released()), this,SLOT(handleButtonClientInput()));
    connect(clientViewButton, SIGNAL(released()), this,SLOT(handleButtonClientView()));

    mediator = new CUACSController();
    animalIterator = mediator->getAnimalIterator();
    clientIterator = mediator->getClientIterator();

    Tests::testACM(mediator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonAnimalInput()
{
    AnimalInputDiag diag(mediator, this);
    diag.setWindowTitle("Input Animal");
    diag.exec();
}

void MainWindow::handleButtonAnimalView()
{
    AnimalListView diag(mediator, this);
    diag.setWindowTitle("Animal List");
    diag.exec();
}
void MainWindow::handleButtonClientInput()
{
    ClientInputDiag diag(mediator, this);
    diag.setWindowTitle("Input Client");
    diag.exec();
}

void MainWindow::handleButtonClientView()
{
   ClientListView diag(mediator, this);
   diag.setWindowTitle("Client List");
   diag.exec();
}
