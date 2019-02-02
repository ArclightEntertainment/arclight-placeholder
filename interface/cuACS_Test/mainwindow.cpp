#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect pointers to buttons
    viewButton = ui->viewButton;
    inputButton = ui->inputButton;

    //connect buttons to slots
    connect(viewButton, SIGNAL(released()), this,SLOT(handleButtonView()));
    connect(inputButton, SIGNAL(released()), this,SLOT(handleButtonInput()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete viewButton;
    delete inputButton;
}

void MainWindow::handleButtonInput()
{
    std::cout << "Pushed Input Button!" << std::endl;
    InputDiag diag(this);
    diag.exec();
}

void MainWindow::handleButtonView()
{
    std::cout << "Pushed View Button!" << std::endl;
    //
}
