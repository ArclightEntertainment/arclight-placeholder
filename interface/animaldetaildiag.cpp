#include "animaldetaildiag.h"
#include "ui_animaldetaildialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalDetailDiag::AnimalDetailDiag(AnimalManager *manager, Animal *subject, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;

    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));

    aManager = manager;
    aSubject = subject;
    updateFields();
}


void AnimalDetailDiag::handleButtonClose()
{
    close();
}

AnimalDetailDiag::~AnimalDetailDiag()
{
    delete ui;
}

void AnimalDetailDiag::updateFields()
{
    //Fields
    QLineEdit *lineEdits[NUMLINES];
    lineEdits[0] = ui->nameLineEdit;
    lineEdits[0]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[1] = ui->idLineEdit;
    lineEdits[1]->setText(QString::number(aSubject->getShelterID()));
    lineEdits[2] = ui->speciesLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getSpecies()));
    lineEdits[3] = ui->breedLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getBreed()));
    lineEdits[4] = ui->sexLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getSexString()));
    lineEdits[5] = ui->ageLineEdit;
    lineEdits[5]->setText(QString::number(aSubject->getAge()));
    lineEdits[6] = ui->careLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getLevelOfCareString()));
    lineEdits[7] = ui->trainingLineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getTrainingString()));
    lineEdits[8] = ui->trainabilityLineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getTrainabilityString()));
    lineEdits[9] = ui->adultAffinityLineEdit;
    lineEdits[9]->setText(QString::fromStdString(aSubject->getAffForPeopleString()));
    lineEdits[10] = ui->childAffinityLineEdit;
    lineEdits[10]->setText(QString::fromStdString(aSubject->getAffForChildrenString()));
    lineEdits[11] = ui->animalAffinityLineEdit;
    lineEdits[11]->setText(QString::fromStdString(aSubject->getAffForAnimalsString()));
    lineEdits[12] = ui->approachabilityLineEdit;
    lineEdits[12]->setText(QString::fromStdString(aSubject->getApproachabilityString()));
    lineEdits[13] = ui->timeCommitmentLineEdit;
    lineEdits[13]->setText(QString::fromStdString(aSubject->getTimeCommitmentString()));
    lineEdits[14] = ui->dietLineEdit;
    lineEdits[14]->setText(QString::fromStdString(aSubject->getDietNeeds()));
    lineEdits[15] = ui->mobilityLineEdit;
    lineEdits[15]->setText(QString::fromStdString(aSubject->getMobilityNeeds()));
    lineEdits[16] = ui->disabilityLineEdit;
    lineEdits[16]->setText(QString::fromStdString(aSubject->getDisabilityNeeds()));
    lineEdits[17] = ui->immunizedLineEdit;
    lineEdits[17]->setText((aSubject->isImmunized()) ? QString("Yes") : QString("No"));

    for (int i = 0; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
    }


    QTextEdit *textEdits[NUMTEXT];
    textEdits[0] = ui->bioTextEdit;
    textEdits[0]->setText(QString::fromStdString(aSubject->getBiography()));
    textEdits[1] = ui->historyTextEdit;
    textEdits[1]->setText(QString::fromStdString(aSubject->getAbuseHistory()));

    for (int i = 0; i < NUMTEXT; i++)
    {
        textEdits[i]->setReadOnly(true);
    }


    QProgressBar *sliders[NUMBARS];
    sliders[0] = ui->trainingBar;
    sliders[0]->setValue(aSubject->getTrainingLevel());
    sliders[1] = ui->trainabilityBar;
    sliders[1]->setValue(aSubject->getTrainabilityLevel());
    sliders[2] = ui->adultAffinityBar;
    sliders[2]->setValue(aSubject->getAffForPeople());
    sliders[3] = ui->childAffinityBar;
    sliders[3]->setValue(aSubject->getAffForChildren());
    sliders[4] = ui->childAffinityBar;
    sliders[4]->setValue(aSubject->getAffForAnimals());
    sliders[5] = ui->approachabilityBar;
    sliders[5]->setValue(aSubject->getApproachability());
    sliders[6] = ui->timeCommitmentBar;
    sliders[6]->setValue(aSubject->getTimeCommitment());
}
