#include "LoginDialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(int * i, CUACSController * med, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    loginButton = ui->loginButton;
    closeButton = ui->closeButton;
    staffButton = ui->staffButton;
    clientButton = ui->clientButton;
    nameLabel=ui->nameLabel;

    fNameLineEdit = ui->fNameLineEdit;
    lNameLineEdit = ui->lNameLineEdit;

    nameLabel->setVisible(false);
    fNameLineEdit->setVisible(false);
    lNameLineEdit->setVisible(false);
    loginButton->setVisible(false);
    id = i;
    mediator = med;

    connect(loginButton, SIGNAL(released()), this,SLOT(handleButtonLogin()));
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(staffButton, SIGNAL(released()), this,SLOT(handleButtonStaff()));
    connect(clientButton, SIGNAL(released()), this,SLOT(handleButtonClient()));
}


void LoginDialog::handleButtonLogin()
{
    if (mediator->getClientWithName(fNameLineEdit->text().toStdString(), lNameLineEdit->text().toStdString()) != NULL)
    {
	*id = mediator->getClientWithName(fNameLineEdit->text().toStdString(), lNameLineEdit->text().toStdString())->getID();
	close();
    }
    else
    {
	staffButton->setVisible(true);
	clientButton->setVisible(true);
	loginButton->setVisible(false);
	nameLabel->setVisible(false);
	fNameLineEdit->setVisible(false);
	lNameLineEdit->setVisible(false);
	fNameLineEdit->setText("");
	lNameLineEdit->setText("");
    }
}
void LoginDialog::handleButtonClose()
{
    *id = 100000;
    std::cout<<"*id: "<<*id<<std::endl;
    close();
}
void LoginDialog::handleButtonStaff()
{
    *id = 100001;
    close();
}
void LoginDialog::handleButtonClient()
{
    loginButton->setVisible(true);
    fNameLineEdit->setVisible(true);
    lNameLineEdit->setVisible(true);
    staffButton->setVisible(false);
    clientButton->setVisible(false);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
