#include "ClientInputDiag.h"
#include "ui_clientinputdialog.h"

#include <iostream>

ClientInputDiag::ClientInputDiag(CUACSController *med, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientInputDiag)
{
    ui->setupUi(this);

    saveButton = ui->saveButton;
    cancelButton = ui->cancelButton;

    connect(saveButton, SIGNAL(released()), this,SLOT(handleButtonSave()));
    connect(cancelButton, SIGNAL(released()), this,SLOT(handleButtonCancel()));


    mediator = med;

    QValidator *pNumValidator = new QRegExpValidator(QRegExp("([0-9]|-|\\)|\\(|\\ ){1,20}"), this);
    QValidator *postValidator = new QRegExpValidator(QRegExp("([0-9]|[a-z]|[A-Z]|\\ ){1,7}"), this);
    QValidator *textValidator = new QRegExpValidator(QRegExp("([a-z]|[A-Z]|\\ ){1,30}"), this);

    newClientID = mediator->getNextClientID();
    ui->idLineEdit->setText(QString::number(newClientID));
    ui->idLineEdit->setEnabled(false);
    ui->cityLineEdit->setValidator(textValidator);
    ui->provLineEdit->setValidator(textValidator);
    ui->countryLineEdit->setValidator(textValidator);
    ui->phoneLineEdit->setValidator(pNumValidator);
    ui->postalLineEdit->setValidator(postValidator);
}

std::string ClientInputDiag::getPhoneNumberFromUI()
{
    std::string startString = ui->phoneLineEdit->text().toStdString();
    std::string totalString = "";
    for (int i = 0; i < (int)startString.length(); i++)
    {
        if (isdigit(startString[i]))
        {
            totalString += startString[i];
        }
    }

    if (startString.length() < 10)
    {
        return "";
    }
    return totalString;

}
void ClientInputDiag::handleButtonSave()
{
    //important values
    //verify -> populate
    if (checkInputValid())
    {
        mediator->addClient(ui->titleComboBox->currentText().toStdString(),
                                             newClientID,
                                             ui->firstNameLineEdit->text().toStdString(),
                                             ui->lastNameLineEdit->text().toStdString(),
                                             getPhoneNumberFromUI()
                                             );

        mediator->populateClientAddress(ui->add1LineEdit->text().toStdString(),
                                             ui->add2LineEdit->text().toStdString(),
                                             ui->cityLineEdit->text().toStdString(),
                                             ui->provLineEdit->text().toStdString(),
                                             ui->countryLineEdit->text().toStdString(),
                                             ui->postalLineEdit->text().toStdString()
                                             );

        //mediator->pushClientToDB(index);
        mediator->finalizeClient();
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
    bool phone = getPhoneNumberFromUI().length()>0;
    bool postal = !ui->postalLineEdit->text().isEmpty();
    bool country = !ui->countryLineEdit->text().isEmpty();
    bool prov = !ui->provLineEdit->text().isEmpty();
    bool city = !ui->cityLineEdit->text().isEmpty();
    bool add1 = !ui->add1LineEdit->text().isEmpty();

    if (!title){errString.append("Must Input Title!\n"); valid = false;}
    if (!fname){errString.append("Missing First Name!\n"); valid = false;}
    if (!lname){errString.append("Missing Last Name!\n"); valid = false;}
    if (!phone){errString.append("Missing or Invalid Phone Number!\n"); valid = false;}
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
void ClientInputDiag::handleButtonCancel()
{
    close();
}

ClientInputDiag::~ClientInputDiag()
{
    delete ui;
}


