#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect pointers to buttons
    viewButton = ui->viewButton;
    inputButton = ui->inputButton;
    //TEST: testButton = ui->testButton;

    //connect buttons to slots
    connect(viewButton, SIGNAL(released()), this,SLOT(handleButtonView()));
    connect(inputButton, SIGNAL(released()), this,SLOT(handleButtonInput()));
    //TEST: connect(testButton, SIGNAL(released()), this,SLOT(handleButtonTest()));

    animalManager = new AnimalManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonInput()
{
    std::cout << "Pushed Input Button!" << std::endl;
    InputDiag diag(animalManager, this);
    diag.exec();
}

void MainWindow::handleButtonView()
{
    std::cout << "Pushed View Button!" << std::endl;
    ListView diag(animalManager, this);
    diag.exec();
}

//TEST: void MainWindow::handleButtonTest()
//TEST: {
//TEST:     std::cout << "Pushed Test Button!" << std::endl;
//TEST:     animalManager->testFunc();
//TEST: }
