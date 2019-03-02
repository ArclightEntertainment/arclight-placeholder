#include "AnimalInputDiag.h"
#include "ui_inputdialog.h"
#include <iostream>

//Requires parent widget and manager
InputDiag::InputDiag(AnimalManager *manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDiag)
{
    ui->setupUi(this);

    saveButton = ui->saveButton;
    cancelButton = ui->cancelButton;

    //set validators for text fields, limiting valid characters
    QValidator *validator = new QRegExpValidator(QRegExp("([A-Z]|[a-z]|-|.){1,50}"), this);
    ui->nameLineEdit->setValidator(validator);
    ui->breedLineEdit->setValidator(validator);

    //link buttons and functions
    connect(saveButton, SIGNAL(released()), this,SLOT(handleButtonSave()));
    connect(cancelButton, SIGNAL(released()), this,SLOT(handleButtonCancel()));

    aManager = manager;
}

//Save Handler
void InputDiag::handleButtonSave()
{
    //important values
    bool name = !ui->nameLineEdit->text().isEmpty();
    bool species = QString::compare(ui->speciesSelector->currentText(), "Species");  //!= Species
    bool sex = QString::compare(ui->sexSelector->currentText(), "Sex");  //!= Sex
    bool age = QString::compare(ui->ageSpinBox->text(), "0");
    //verify -> populate
    if (name && species && sex && age)
    {
        int index = aManager -> addAnimal(
                    ui->nameLineEdit->text().toStdString(),
                    ui->ageSpinBox->text().toInt(),
                    ui->sexSelector->currentText().at(0).toLatin1(),
                    ui->speciesSelector->currentText().toStdString(),
                    ui->breedLineEdit->text().toStdString(),
                    ui->careSlider->value()
                    );
        aManager->updateAnimalSocial(
                    index,
                    ui->trainingSlider->value(),
                    ui->trainabilitySlider->value(),
                    ui->peopleSlider->value(),
                    ui->childSlider->value(),
                    ui->animalSlider->value(),
                    ui->approachabilitySlider->value(),
                    ui->timeSlider->value()
                    );
        aManager->updateAnimalHistory(
                    index,
                    ui->immunizedCheckbox->isChecked(),
                    ui->dietLineEdit->text().toStdString(),
                    ui->mobilityLineEdit->text().toStdString(),
                    ui->disabLineEdit->text().toStdString(),
                    ui->bioTextEdit->toPlainText().toStdString(),
                    ui->aHistTextEdit->toPlainText().toStdString()
                    );
        //push the animal to the DB
        aManager->pushAnimalToDB(index);
        close();
    } else {
        //Create a warning dialog box, text based on what fields are missing
        QMessageBox warningBox;
        warningBox.setText("An Error occured when Saving:");
        std::string warnString = "";

        if (!name){warnString.append("Name Missing!\n");}
        if (!species){warnString.append("Species Missing!\n");}
        if (!sex){warnString.append("Sex Missing!\n");}
        if (!age){warnString.append("Age Missing!\n");}

        warningBox.setInformativeText(QString::fromStdString(warnString));
        warningBox.setStandardButtons(QMessageBox::Ok);
        warningBox.setDefaultButton(QMessageBox::Ok);
        warningBox.exec();
    }
}

//close on cancel
void InputDiag::handleButtonCancel()
{
    close();
}

//destructor
InputDiag::~InputDiag()
{
    delete ui;
}
