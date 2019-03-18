#include "AnimalDetailDiag.h"
#include "ui_animaldetaildialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalDetailDiag::AnimalDetailDiag(AnimalManager *manager, Animal *subject, bool canEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    editButton = ui->editButton;

    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(editButton, SIGNAL(released()), this,SLOT(handleButtonEdit()));

    editMode = canEdit;

    aManager = manager;
    aSubject = subject;
    updateFields();
    setEditable(editMode);
}


void AnimalDetailDiag::handleButtonClose()
{
    close();
}

void AnimalDetailDiag::handleButtonEdit()
{
    if (editMode == false)
    {
        editButton->setText("Edit");
    }
    else
    {
        editButton->setText("Save");
    }
    editMode = !editMode;
    setEditable(editMode);
}

AnimalDetailDiag::~AnimalDetailDiag()
{
    delete ui;
}

void AnimalDetailDiag::updateFields()
{
    //Fields
    lineEdits[0] = ui->idLineEdit;
    lineEdits[0]->setText(QString::number(aSubject->getShelterID()));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[2] = ui->speciesLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getSpecies()));
    lineEdits[3] = ui->breedLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getBreed()));
    lineEdits[4] = ui->sexLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getSexString()));
    lineEdits[5] = ui->ageLineEdit;
    lineEdits[5]->setText(QString::number(aSubject->getAge()));
    lineEdits[6] = ui->dietLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getDietNeeds()));
    lineEdits[7] = ui->mobilityLineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getMobilityNeeds()));
    lineEdits[8] = ui->disabilityLineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getDisabilityNeeds()));
    lineEdits[9] = ui->immunizedLineEdit;
    lineEdits[9]->setText((aSubject->isImmunized()) ? QString("Yes") : QString("No"));
    lineEdits[10] = ui->expenditureLineEdit;
    lineEdits[10]->setText(QString::number(aSubject->getEstimatedCost()));
    lineEdits[11] = ui->maxAgeLineEdit;
    lineEdits[11]->setText(QString::number(aSubject->getLifeExpectancy()));
    lineEdits[12] = ui->energyLineEdit;
    lineEdits[12]->setText(QString::fromStdString(aSubject->getLevelOfEnergyString()));
    lineEdits[13] = ui->trainingLineEdit;
    lineEdits[13]->setText(QString::fromStdString(aSubject->getTrainingString()));
    lineEdits[14] = ui->trainabilityLineEdit;
    lineEdits[14]->setText(QString::fromStdString(aSubject->getTrainabilityString()));
    lineEdits[15] = ui->adultAffinityLineEdit;
    lineEdits[15]->setText(QString::fromStdString(aSubject->getAffForPeopleString()));
    lineEdits[16] = ui->childAffinityLineEdit;
    lineEdits[16]->setText(QString::fromStdString(aSubject->getAffForChildrenString()));
    lineEdits[17] = ui->animalAffinityLineEdit;
    lineEdits[17]->setText(QString::fromStdString(aSubject->getAffForAnimalsString()));
    lineEdits[18] = ui->approachabilityLineEdit;
    lineEdits[18]->setText(QString::fromStdString(aSubject->getApproachabilityString()));
    lineEdits[19] = ui->timeCommitmentLineEdit;
    lineEdits[19]->setText(QString::fromStdString(aSubject->getTimeCommitmentString()));
    lineEdits[20] = ui->careLineEdit;
    lineEdits[20]->setText(QString::fromStdString(aSubject->getLevelOfCareString()));

    lineEdits[0]->setReadOnly(true);
    lineEdits[0]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));

    for (int i = 12; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }

    textEdits[0] = ui->bioTextEdit;
    textEdits[0]->setText(QString::fromStdString(aSubject->getBiography()));
    textEdits[1] = ui->historyTextEdit;
    textEdits[1]->setText(QString::fromStdString(aSubject->getAbuseHistory()));

    progBars[0] = ui->trainingBar;
    progBars[0]->setValue(aSubject->getTrainingLevel());
    progBars[1] = ui->trainabilityBar;
    progBars[1]->setValue(aSubject->getTrainabilityLevel());
    progBars[2] = ui->adultAffinityBar;
    progBars[2]->setValue(aSubject->getAffForPeople());
    progBars[3] = ui->childAffinityBar;
    progBars[3]->setValue(aSubject->getAffForChildren());
    progBars[4] = ui->animalAffinityBar;
    progBars[4]->setValue(aSubject->getAffForAnimals());
    progBars[5] = ui->approachabilityBar;
    progBars[5]->setValue(aSubject->getApproachability());
    progBars[6] = ui->timeCommitmentBar;
    progBars[6]->setValue(aSubject->getTimeCommitment());
    progBars[7] = ui->energyBar;
    progBars[7]->setValue(aSubject->getLevelOfEnergy());
    progBars[8] = ui->careBar;
    progBars[8]->setValue(aSubject->getLevelOfCare());


    sliders[0] = new QSlider();
    sliders[0]->setMaximum(2);
    sliders[0]->setValue(aSubject->getTrainingLevel());
    sliders[1] = new QSlider();
    sliders[1]->setMaximum(2);
    sliders[1]->setValue(aSubject->getTrainabilityLevel());
    sliders[2] = new QSlider();
    sliders[2]->setMaximum(2);
    sliders[2]->setValue(aSubject->getAffForPeople());
    sliders[3] = new QSlider();
    sliders[3]->setMaximum(2);
    sliders[3]->setValue(aSubject->getAffForChildren());
    sliders[4] = new QSlider();
    sliders[4]->setMaximum(2);
    sliders[4]->setValue(aSubject->getAffForAnimals());
    sliders[5] = new QSlider();
    sliders[5]->setMaximum(2);
    sliders[5]->setValue(aSubject->getApproachability());
    sliders[6] = new QSlider();
    sliders[6]->setMaximum(2);
    sliders[6]->setValue(aSubject->getTimeCommitment());
    sliders[7] = new QSlider();
    sliders[7]->setMaximum(2);
    sliders[7]->setValue(aSubject->getLevelOfEnergy());
    sliders[8] = new QSlider();
    sliders[8]->setMaximum(2);
    sliders[8]->setValue(aSubject->getLevelOfCare());
}

void AnimalDetailDiag::setEditable (bool canEdit)
{
    for (int i = 1; i < 12; i++)
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

    for (int i = 0; i < NUMTEXT; i++)
    {
        textEdits[i]->setReadOnly(!canEdit);
        if (canEdit)
        {
            textEdits[i]->setStyleSheet(QString::fromStdString(""));
        }
        else
        {
            textEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }
}
