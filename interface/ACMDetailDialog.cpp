#include "ACMDetailDialog.h"
#include "ui_acmdetaildialog.h"

#include "AnimalDetailDiag.h"
#include "ClientDetailDiag.h"
#include "Attributes.h"

ACMDetailDialog::ACMDetailDialog(CUACSController * med, int cID, AnimalClientPair * p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMDetailDialog),
    pair(p),
    mediator(med),
    currentID(cID)
{
    ui->setupUi(this);

    animalButton = ui->animalButton;
    clientButton = ui->clientButton;
    closeButton = ui->closeButton;
    comments = ui->commentLayout;

    connect(animalButton , SIGNAL(released()), this,SLOT(handleButtonAnimal()));
    connect(clientButton, SIGNAL(released()), this,SLOT(handleButtonClient()));
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));

    populateAnimal();
    populateClient();
    QString compatabilityString = QString::number(pair->getCompatibility()) + QString::fromStdString(" %");
    ui->compatabilityLineEdit->setText(compatabilityString);
    ui->compatabilityLineEdit->setReadOnly(true);
    ui->compatabilityLineEdit->setAlignment(Qt::AlignHCenter);
    ui->compatabilityLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
}

void ACMDetailDialog::addComments(std::string commentArr[], int count)
{
    for (int i = 0; i < count; i++)
    {
	std::string line = "";
	line.append(std::to_string(i));
	line.append(". ");
	line.append(commentArr[i]);
	QLabel * current = new QLabel(QString::fromStdString(line));
	current->setAlignment(Qt::AlignHCenter);
	comments->addWidget(current);
    }
}
void ACMDetailDialog::handleButtonAnimal()
{
    AnimalDetailDiag diag(mediator, pair->getAnimal(), false, this);
    diag.setWindowTitle(QString::fromStdString(pair->getAnimal()->getName()));
    diag.exec();
}
void ACMDetailDialog::handleButtonClient()
{
    ClientDetailDiag diag(mediator, currentID, pair->getClient(), false, this);
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
    ui->aNameLineEdit->setReadOnly(true);
    ui->aNameLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aIDLineEdit->setText(QString::number(a->getID()));
    ui->aIDLineEdit->setReadOnly(true);
    ui->aIDLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aSpeciesLineEdit->setText(QString::fromStdString(a->getString(static_cast<int>(AnimalAttribute::SPECIES))));
    ui->aSpeciesLineEdit->setReadOnly(true);
    ui->aSpeciesLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aBreedLineEdit->setText(QString::fromStdString(a->getString(static_cast<int>(AnimalAttribute::BREED))));
    ui->aBreedLineEdit->setReadOnly(true);
    ui->aBreedLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aSexLineEdit->setText(QString::fromStdString((a->getString(static_cast<int>(AnimalAttribute::SEX)) == "M") ? "Male" : "Female"));
    ui->aSexLineEdit->setReadOnly(true);
    ui->aSexLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aAgeLineEdit->setText(QString::number(a->getAge()));
    ui->aAgeLineEdit->setReadOnly(true);
    ui->aAgeLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aMaxAgeLineEdit->setText(QString::number(a->getInt(static_cast<int>(AnimalAttribute::LIFE_EXPECTANCY))));
    ui->aMaxAgeLineEdit->setReadOnly(true);
    ui->aMaxAgeLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aImmunizedLineEdit->setText(QString::fromStdString((a->getBool(static_cast<int>(AnimalAttribute::IMMUNIZED)) ? "Yes" : "No")));
    ui->aImmunizedLineEdit->setReadOnly(true);
    ui->aImmunizedLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->aExpenditureLineEdit->setText(QString::number(a->getInt(static_cast<int>(AnimalAttribute::MONTHLY_EXPENDITURE))));
    ui->aExpenditureLineEdit->setReadOnly(true);
    ui->aExpenditureLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
}
void ACMDetailDialog::populateClient()
{
    UClient * c = pair->getClient();
    ui->cNameLineEdit->setText(QString::fromStdString(c->getName() + " " + c->getString(static_cast<int>(ClientAttribute::LAST_NAME))));
    ui->cNameLineEdit->setReadOnly(true);
    ui->cNameLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cTitleLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::PREF_TITLE))));
    ui->cTitleLineEdit->setReadOnly(true);
    ui->cTitleLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cIDLineEdit->setText(QString::number(c->getID()));
    ui->cIDLineEdit->setReadOnly(true);
    ui->cIDLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cPhoneLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::PHONE_NUMBER))));
    ui->cPhoneLineEdit->setReadOnly(true);
    ui->cPhoneLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cPostalLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::POSTAL_CODE))));
    ui->cPostalLineEdit->setReadOnly(true);
    ui->cPostalLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cCityLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::CITY))));
    ui->cCityLineEdit->setReadOnly(true);
    ui->cCityLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cProvLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::SUBNATIONAL_DIVISION))));
    ui->cProvLineEdit->setReadOnly(true);
    ui->cProvLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cCountryLineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::COUNTRY))));
    ui->cCountryLineEdit->setReadOnly(true);
    ui->cCountryLineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cAdd1LineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::STREET_LINE_1))));
    ui->cAdd1LineEdit->setReadOnly(true);
    ui->cAdd1LineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
    ui->cAdd2LineEdit->setText(QString::fromStdString(c->getString(static_cast<int>(ClientAttribute::STREET_LINE_2))));
    ui->cAdd2LineEdit->setReadOnly(true);
    ui->cAdd2LineEdit->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
}

ACMDetailDialog::~ACMDetailDialog()
{
    delete ui;
}
