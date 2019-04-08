#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "Tests.h"
#include "AnimalInputDiag.h"
#include "ClientInputDiag.h"
#include "AnimalListView.h"
#include "ClientListView.h"
#include "ACMListView.h"
#include "LoginDialog.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentID(-1)
{
    ui->setupUi(this);

    //connect pointers to buttons
    animalViewButton = ui->animalViewButton;
    animalInputButton = ui->animalInputButton;
    clientViewButton = ui->clientViewButton;
    clientInputButton = ui->clientInputButton;
    logOutButton = ui->logOutButton;

    acmButton = ui->acmButton;

    //connect buttons to slots
    connect(animalInputButton, SIGNAL(released()), this,SLOT(handleButtonAnimalInput()));
    connect(animalViewButton, SIGNAL(released()), this,SLOT(handleButtonAnimalView()));
    connect(clientInputButton, SIGNAL(released()), this,SLOT(handleButtonClientInput()));
    connect(clientViewButton, SIGNAL(released()), this,SLOT(handleButtonClientView()));
    connect(logOutButton, SIGNAL(released()), this,SLOT(Login()));

    connect(acmButton, SIGNAL(released()), this,SLOT(handleButtonACM()));

    mediator = new CUACSController();
    animalIterator = mediator->getAnimalIterator();
    clientIterator = mediator->getClientIterator();

    //Tests::testACM(mediator);
    Login();
}

void MainWindow::Login()
{
    LoginDialog diag(&currentID, mediator, this);
    diag.setWindowTitle("Login");
    diag.exec();

    std::cout << "currentID = " << currentID << std::endl;;
    if (currentID == 100000)
    {
	QTimer::singleShot(0, this, SLOT(close()));
	close();
    }
    else if (currentID < 100000)
    {
	acmButton->setVisible(false);
	clientInputButton->setVisible(false);
	animalInputButton->setVisible(false);
	clientViewButton->setText("View Profile");
    }
    else
    {
	acmButton->setVisible(true);
	clientInputButton->setVisible(true);
	animalInputButton->setVisible(true);
	clientViewButton->setText("View All Clients");
    }
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
    if (currentID == 100001)
    {
	ClientListView diag(mediator, currentID, this);
	diag.setWindowTitle("Client List");
	diag.exec();
    }
    else
    {
	ClientDetailDiag diag(mediator, currentID, mediator->getClientWithId(currentID), false, this);
	diag.setWindowTitle(QString::fromStdString(mediator->getClientWithId(currentID)->getName()));
	diag.exec();
    }
}

void MainWindow::handleButtonACM()
{
    ACMListView diag(mediator, currentID, this);
    diag.setWindowTitle("ACM Match List");
    diag.exec();
}
