#include "ClientDetailDiag.h"
#include "ui_clientdetaildialog.h"
#include <iostream>

//Requires parent widget and manager
ClientDetailDiag::ClientDetailDiag(ClientManager *manager, Client *subject, bool canEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    editButton = ui->editButton;
    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(editButton, SIGNAL(released()), this,SLOT(handleButtonEdit()));

    aManager = manager;
    aSubject = subject;

    editMode = canEdit;

    updateFields();
}


void ClientDetailDiag::handleButtonClose()
{
    close();
}
void ClientDetailDiag::handleButtonEdit()
{
    if (editMode == false)
    {
        editButton->setText("Save");
    }
    else
    {
        updateCurrentClient();
        editButton->setText("Edit");
    }
    editMode = !editMode;
    setEditable(editMode);
}


ClientDetailDiag::~ClientDetailDiag()
{
    delete ui;
}

void ClientDetailDiag::updateFields()
{
    //Fields

    lineEdits[0] = ui->titleLineEdit;
    lineEdits[0]->setText(QString::fromStdString(aSubject->getTitle()));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[2] = ui->phoneLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getPhoneNumberString()));
    lineEdits[3] = ui->postalLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getAddress().getPostalCode()));
    lineEdits[4] = ui->cityLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getAddress().getCity()));
    lineEdits[5] = ui->provLineEdit;
    lineEdits[5]->setText(QString::fromStdString(aSubject->getAddress().getSubnationalDivision()));
    lineEdits[6] = ui->countryLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getAddress().getCountry()));
    lineEdits[7] = ui->add1LineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getAddress().getStreetLine1()));
    lineEdits[8] = ui->add2LineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getAddress().getStreetLine2()));
    lineEdits[9] = ui->idLineEdit;
    lineEdits[9]->setText(QString::number(aSubject->getClientID()));
    lineEdits[9]->setReadOnly(true);
    lineEdits[10]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    
    setEditable(false);
}
void ClientDetailDiag::updateCurrentClient()
{

    aSubject->setName(ui->nameLineEdit->text().toStdString());
    aSubject->setString(5, ui->lNameLineEdit->text().toStdString());
    aSubject->setString(6, ui->titleLineEdit->text().toStdString());
    aSubject->setString(7, ui->phoneLineEdit->text().toStdString());
    aSubject->setString(13, ui->postalLineEdit->text().toStdString());
    aSubject->setString(10, ui->cityLineEdit->text().toStdString());
    aSubject->setString(11, ui->provLineEdit->text().toStdString());
    aSubject->setString(12, ui->countryLineEdit->text().toStdString());
    aSubject->setString(8, ui->add1LineEdit->text().toStdString());
    aSubject->setString(9, ui->add2LineEdit->text().toStdString());
}


void ClientDetailDiag::setEditable (bool canEdit)
{
    for (int i = 0; i < NUMLINES - 1; i++)
    {
        lineEdits[i]->setReadOnly(!canEdit);
        if (canEdit)
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString(""));
        }
        else
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }
}
