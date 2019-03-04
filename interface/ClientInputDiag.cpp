#include "ClientInputDiag.h"
#include "ui_clientinputdialog.h"

#include <iostream>

ClientInputDiag::ClientInputDiag(ClientManager *cm, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientInputDiag)
{
    ui->setupUi(this);

    saveButton = ui->saveButton;
    proceedButton = ui->proceedButton;
    cancelButton = ui->cancelButton;

    connect(saveButton, SIGNAL(released()), this,SLOT(handleButtonSave()));
    connect(proceedButton, SIGNAL(released()), this,SLOT(handleButtonProceed()));
    connect(cancelButton, SIGNAL(released()), this,SLOT(handleButtonCancel()));


    clientManager = cm;


    newClientID = clientManager->getNextID();
    ui->idLineEdit->setText(QString::number(newClientID));
    ui->idLineEdit->setEnabled(false);
}



void ClientInputDiag::handleButtonSave()
{
    //important values
    //verify -> populate
    if (checkInputValid())
    {
        std::cout << (ui->firstNameLineEdit->text().toStdString() + " " + ui->lastNameLineEdit->text().toStdString()) << std::endl;
        int index = clientManager->addClient(ui->titleComboBox->currentText().toStdString(),
                                             newClientID,
                                             ui->firstNameLineEdit->text().toStdString(),
                                             ui->lastNameLineEdit->text().toStdString(),
                                             ui->phoneLineEdit->text().toStdString()
                                             );

        clientManager->populateClientAddress(index,
                                             ui->add1LineEdit->text().toStdString(),
                                             ui->add2LineEdit->text().toStdString(),
                                             ui->cityLineEdit->text().toStdString(),
                                             ui->provLineEdit->text().toStdString(),
                                             ui->countryLineEdit->text().toStdString(),
                                             ui->postalLineEdit->text().toStdString()
                                             );

        clientManager->pushClientToDB(index);
        close();
    }
}

bool ClientInputDiag::checkInputValid()
{

    std::string errString = "";
    bool valid = true;
    bool title = ui->titleComboBox->currentText().toStdString().compare("Title");
    bool fname = !ui->firstNameLineEdit->text().isEmpty();
    bool lname = !ui->lastNameLineEdit->text().isEmpty();
    bool phone = !ui->phoneLineEdit->text().isEmpty();
    bool postal = !ui->postalLineEdit->text().isEmpty();
    bool country = !ui->countryLineEdit->text().isEmpty();
    bool prov = !ui->provLineEdit->text().isEmpty();
    bool city = !ui->cityLineEdit->text().isEmpty();
    bool add1 = !ui->add1LineEdit->text().isEmpty();

    if (!title){errString.append("Must Input Title!\n"); valid = false;}
    if (!fname){errString.append("Missing First Name!\n"); valid = false;}
    if (!lname){errString.append("Missing Last Name!\n"); valid = false;}
    if (!phone){errString.append("Missing Phone Number!\n"); valid = false;}
    if (!postal){errString.append("Missing Postal Code!\n"); valid = false;}
    if (!country){errString.append("Missing Country!\n"); valid = false;}
    if (!prov){errString.append("Missing Province!\n"); valid = false;}
    if (!city){errString.append("Missing City!\n"); valid = false;}
    if (!add1){errString.append("Missing Address!\n"); valid = false;}

    if (!valid)
    {
        //Create a warning dialog box, text based on what fields are missing
        QMessageBox warningBox;
        warningBox.setText("An Error occured when Saving:");
        warningBox.setInformativeText(QString::fromStdString(errString));
        warningBox.setStandardButtons(QMessageBox::Ok);
        warningBox.setDefaultButton(QMessageBox::Ok);
        warningBox.exec();
    }

    return (valid);
}

//close on cancel
void ClientInputDiag::handleButtonProceed()
{
    std::cout << "Proceed!" << std::endl;
    close();
}

//close on cancel
void ClientInputDiag::handleButtonCancel()
{
    std::cout << "Cancel!" << std::endl;
    close();
}

ClientInputDiag::~ClientInputDiag()
{
    delete ui;
}


