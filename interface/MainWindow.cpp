#include "MainWindow.h"
#include "ui_mainwindow.h"

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
    //TEST: testButton = ui->testButton;

    //connect buttons to slots
    connect(animalInputButton, SIGNAL(released()), this,SLOT(handleButtonAnimalInput()));
    connect(animalViewButton, SIGNAL(released()), this,SLOT(handleButtonAnimalView()));
    connect(clientInputButton, SIGNAL(released()), this,SLOT(handleButtonClientInput()));
    connect(clientViewButton, SIGNAL(released()), this,SLOT(handleButtonClientView()));
    //TEST: connect(testButton, SIGNAL(released()), this,SLOT(handleButtonTest()));

    animalManager = new AnimalManager();
    clientManager = new ClientManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonAnimalInput()
{
    //std::cout << "Pushed Input Button!" << std::endl;
    AnimalInputDiag diag(animalManager, this);
    diag.exec();
}

void MainWindow::handleButtonAnimalView()
{
    //std::cout << "Pushed View Button!" << std::endl;
    ListView diag(animalManager, this);
    diag.exec();
}
void MainWindow::handleButtonClientInput()
{
    //std::cout << "Pushed Input Button!" << std::endl;
    ClientInputDiag diag(clientManager, this);
    diag.exec();
}

void MainWindow::handleButtonClientView()
{
   // std::cout << "Pushed View Button!" << std::endl;
   // ListView diag(clientManager, this);
   // diag.exec();
}
