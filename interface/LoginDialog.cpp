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
    idLabel=ui->idLabel;

    idLineEdit = ui->idLineEdit;
    QValidator *numValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,5}"), this);
    idLineEdit->setValidator(numValidator);
    idLabel->setVisible(false);

    loginButton->setVisible(false);
    idLineEdit->setVisible(false);
    id = i;
    mediator = med;

    connect(loginButton, SIGNAL(released()), this,SLOT(handleButtonLogin()));
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(staffButton, SIGNAL(released()), this,SLOT(handleButtonStaff()));
    connect(clientButton, SIGNAL(released()), this,SLOT(handleButtonClient()));
}


void LoginDialog::handleButtonLogin()
{
    int current = idLineEdit->text().toInt();
    if (mediator->getClientWithId(current) != NULL)
    {
	*id = current;
	close();
    }
    else
    {
	staffButton->setVisible(true);
	clientButton->setVisible(true);
	loginButton->setVisible(false);
	idLineEdit->setVisible(false);
	idLabel->setVisible(false);
	idLineEdit->setText("");
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
    idLineEdit->setVisible(true);
    staffButton->setVisible(false);
    clientButton->setVisible(false);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
