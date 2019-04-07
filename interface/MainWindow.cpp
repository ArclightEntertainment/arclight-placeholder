#include "MainWindow.h"
#include "ui_mainwindow.h"

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

    //connect buttons to slots
    connect(animalInputButton, SIGNAL(released()), this,SLOT(handleButtonAnimalInput()));
    connect(animalViewButton, SIGNAL(released()), this,SLOT(handleButtonAnimalView()));
    connect(clientInputButton, SIGNAL(released()), this,SLOT(handleButtonClientInput()));
    connect(clientViewButton, SIGNAL(released()), this,SLOT(handleButtonClientView()));

    mediator = new CUACSController();
    animalIterator = mediator->getAnimalIterator();
    clientIterator = mediator->getClientIterator();

    LoginDialog diag(&currentID, mediator, this);
    diag.setWindowTitle("Login");
    diag.exec();


    if (currentID == -1)
    {
	close();
    }
    else if (currentID < 100000)
    {
	clientInputButton->setVisible(false);
	animalInputButton->setVisible(false);
	clientViewButton->setText("View Profile");
    }
    else
    {
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
	ClientListView diag(mediator, this);
	diag.setWindowTitle("Client List");
	diag.exec();
    }
    else
    {
	ClientDetailDiag diag(mediator, mediator->getClientWithId(currentID), false, this);
	diag.setWindowTitle(QString::fromStdString(mediator->getClientWithId(currentID)->getName()));
	diag.exec();
    }
}
