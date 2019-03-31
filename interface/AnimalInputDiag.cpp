#include "AnimalInputDiag.h"
#include "ui_animalinputdialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalInputDiag::AnimalInputDiag(AnimalManager *manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalInputDiag)
{
    ui->setupUi(this);

    saveButton = ui->saveButton;
    cancelButton = ui->cancelButton;

    //set validators for text fields, limiting valid characters
    QValidator *textValidator = new QRegExpValidator(QRegExp("([A-Z]|[a-z]|-|.){1,50}"), this);
    QValidator *expValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,50}"), this);
    ui->nameLineEdit->setValidator(textValidator);
    ui->breedLineEdit->setValidator(textValidator);
    ui->expenditureLineEdit->setValidator(expValidator);

    //link buttons and functions
    connect(saveButton, SIGNAL(released()), this,SLOT(handleButtonSave()));
    connect(cancelButton, SIGNAL(released()), this,SLOT(handleButtonCancel()));

    aManager = manager;
    ui->idLineEdit->setEnabled(false);
    ui->idLineEdit->setText(QString::number(aManager->getNextID()));
}

//Save Handler
void AnimalInputDiag::handleButtonSave()
{
    //important values
    bool name = !ui->nameLineEdit->text().isEmpty();
    bool id = aManager->checkID(ui->idLineEdit->text().toInt());
    bool species = QString::compare(ui->speciesSelector->currentText(), "Species");  //!= Species
    bool sex = QString::compare(ui->sexSelector->currentText(), "Sex");  //!= Sex
    bool age = QString::compare(ui->ageSpinBox->text(), "0");
    bool life = QString::compare(ui->maxLifeSpinBox->text(), "0");
    bool expenditure = getExpenditureFromUI();
    //verify -> populate
    if (name && species && sex && age && id && expenditure && life)
    {
        int index = aManager -> addAnimal(
                    ui->idLineEdit->text().toInt(),
                    getExpenditureFromUI(),
                    ui->nameLineEdit->text().toStdString(),
                    ui->ageSpinBox->text().toInt(),
                    ui->maxLifeSpinBox->text().toInt(),
                    ui->sexSelector->currentText().at(0).toLatin1(),
                    ui->speciesSelector->currentText().toStdString(),
                    ui->breedLineEdit->text().toStdString(),
                    ui->careSlider->value(),
                    ui->energySlider->value()
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
        if (!id)
        {
            warnString.append("Shelter ID Missing or in use!\n");
            warnString.append("Suggest using: " + std::to_string(aManager->getNextID()) + "\n");
        }
        if (!species){warnString.append("Species Missing!\n");}
        if (!sex){warnString.append("Sex Missing!\n");}
        if (!age){warnString.append("Age Missing!\n");}
        if (!life){warnString.append("Life Expectancy Missing!\n");}

        warningBox.setInformativeText(QString::fromStdString(warnString));
        warningBox.setStandardButtons(QMessageBox::Ok);
        warningBox.setDefaultButton(QMessageBox::Ok);
        warningBox.exec();
    }
}

//close on cancel
void AnimalInputDiag::handleButtonCancel()
{
    close();
}

int AnimalInputDiag::getExpenditureFromUI()
{
    QString inputString = ui->expenditureLineEdit->text();
    QString newString = "";
    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i].isDigit())
        {
            newString.append(inputString[i]);
        }
    }

    if (newString.toInt() > 0)
    {
        return newString.toInt();
    }
    else
    {
        return 0;
    }
}

//destructor
AnimalInputDiag::~AnimalInputDiag()
{
    delete ui;
}
