#include "ACMDetailDialog.h"
#include "ui_acmdetaildialog.h"

#include "AnimalDetailDiag.h"
#include "ClientDetailDiag.h"
#include "Attributes.h"

ACMDetailDialog::ACMDetailDialog(CUACSController * med, AnimalClientPair * p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMDetailDialog),
    pair(p),
    mediator(med)
{
    ui->setupUi(this);

    animalButton = ui->animalButton;
    clientButton = ui->clientButton;
    closeButton = ui->closeButton;

    connect(animalButton , SIGNAL(released()), this,SLOT(handleButtonAnimal()));
    connect(clientButton, SIGNAL(released()), this,SLOT(handleButtonClient()));
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));

    populateAnimal();
    populateClient();

    ui->compatabilityLineEdit->setText(QString::number(pair->getCompatibility()));
}

void ACMDetailDialog::handleButtonAnimal()
{
    AnimalDetailDiag diag(mediator, pair->getAnimal(), false, this);
    diag.setWindowTitle(QString::fromStdString(pair->getAnimal()->getName()));
    diag.exec();
}
void ACMDetailDialog::handleButtonClient()
{
    ClientDetailDiag diag(mediator, pair->getClient(), false, this);
    diag.setWindowTitle(QString::fromStdString(pair->getClient()->getName()));
    diag.exec();
}
void ACMDetailDialog::handleButtonClose()
{
    close();
}

void ACMDetailDialog::populateAnimal()
{
    UAnimal * a = pair->getAnimal();
    ui->aNameLineEdit->setText(QString::fromStdString(a->getName()));
    ui->aIDLineEdit->setText(QString::number(a->getID()));
    ui->aSpeciesLineEdit->setText(QString::fromStdString(a->getString(static_cast<int>(AnimalAttribute::SPECIES))));
    ui->aBreedLineEdit->setText(QString::fromStdString(a->getString(static_cast<int>(AnimalAttribute::BREED))));
    ui->aSexLineEdit->setText(QString::fromStdString(a->getString(static_cast<int>(AnimalAttribute::SEX))));
    ui->aAgeLineEdit->setText(QString::number(a->getInt(static_cast<int>(AnimalAttribute::AGE))));
    ui->aMaxAgeLineEdit->setText(QString::number(a->getInt(static_cast<int>(AnimalAttribute::LIFE_EXPECTANCY))));
    ui->aImmunizedLineEdit->setText(QString::fromStdString((a->getBool(static_cast<int>(AnimalAttribute::IMMUNIZED)) ? "Yes" : "No")));
    ui->aExpenditureLineEdit->setText(QString::number(a->getInt(static_cast<int>(AnimalAttribute::MONTHLY_EXPENDITURE))));
}
void ACMDetailDialog::populateClient()
{
    UClient * c = pair->getClient();
    ui->cNameLineEdit->setText(QString::fromStdString(c->getName()));
    ui->cTitleLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::PREF_TITLE))));
    ui->cIDLineEdit->setText(QString::number(c->getInt(static_cast<int>(ClientAttribute::ID))));
    ui->cPhoneLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::PHONE_NUMBER))));
    ui->cPostalLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::POSTAL_CODE))));
    ui->cCityLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::CITY))));
    ui->cProvLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::SUBNATIONAL_DIVISION))));
    ui->cCountryLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::COUNTRY))));
    ui->cAdd1LineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::STREET_LINE_1))));
    ui->cAdd2LineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::STREET_LINE_2))));
}

ACMDetailDialog::~ACMDetailDialog()
{
    delete ui;
}
