#include "QuestionnaireDialog.h"
#include "ui_questionnairedialog.h"
#include<iostream>

QuestionnaireDialog::QuestionnaireDialog(CUACSController *med, Entity * target, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionnaireDialog),
    current(0),
    subject(target),
    mediator(med)
{
    ui->setupUi(this);

    qText = ui->questionLabel;
    aLayout = ui->answerLayout;
    exitButton = ui->exitButton;
    nextButton = ui->nextButton;

    connect(exitButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(nextButton, SIGNAL(released()), this,SLOT(handleButtonConfirm()));

    questions = new Question*[NUMQUESTIONS];
    answers = new std::pair<int, ClientAttribute>[NUMQUESTIONS];
    numAnswers=0;

    questions[0] = new SmallIntQuestion(std::string("How old are you?"), ClientAttribute::AGE);
    questions[1] = new BoolQuestion(std::string("Are there children under the age of 12 present in your home?"), ClientAttribute::HAS_CHILDREN_UNDER_TWELVE);
    questions[2] = new BoolQuestion(std::string("Is your pet likely to come in contact with other animals?"), ClientAttribute::HAS_PETS);
    questions[3] = new SmallIntQuestion(std::string("How long do you expect to be caring for your new pet?"), ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION);
    questions[4] = new LargeIntQuestion(std::string("What is your maximum monthly budget for taking care of an animal?"), ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL);
    questions[5] = new SmallIntQuestion(std::string("How many minutes per day can you devote to caring for an animal?"), ClientAttribute::AVAILABILITY_PER_DAY);
    questions[6] = new FiveLevelQuestion(std::string("How physically mobile are you?\n(LOW = Extremely Limited, HIGH = Very Active)"), ClientAttribute::LEVEL_OF_MOBILITY);
    questions[7] = new FiveLevelQuestion(std::string("How patient do others consider you?\n(LOW = Short Tempered, HIGH = Zen AF Fam)"), ClientAttribute::LEVEL_OF_PATIENCE);
    questions[8] = new FiveLevelQuestion(std::string("How experienced are you with pets?\n(LOW = Never Before, HIGH = Many Years of experience)"), ClientAttribute::PREVIOUS_EXPERIENCE);
    questions[9] = new FiveLevelQuestion(std::string("How physically affectionate are you with animals?\n(LOW = Shy, HIGH = Cuddle Machine)"), ClientAttribute::PHYSICAL_AFFECTION);

}
void QuestionnaireDialog::handleButtonClose()
{
    close();
}
void QuestionnaireDialog::handleButtonConfirm()
{
    if (current < NUMQUESTIONS)
    {
	collectAnswer();
	current++;
	setStage();
	if (current == NUMQUESTIONS-1)
	{
	    nextButton->setText("Save");
	}
    }
    else
    {
	updateClient();
	close();
    }
}
void QuestionnaireDialog::updateClient()
{
    //HANDLE CLIENT STUFF HERE!!!
    for (int i = 0; i < numAnswers; i++)
    {
	std::cout << "Value: " << std::get<0>(answers[i]) << " | ID: " << static_cast<int>(std::get<1>(answers[i])) << std::endl;
    }
    mediator->populateClientProfile(
		subject,
		std::get<0>(answers[0]),
		std::get<0>(answers[1]),
		std::get<0>(answers[2]),
		std::get<0>(answers[3]),
		std::get<0>(answers[4]),
		std::get<0>(answers[5]),
		std::get<0>(answers[6]),
		std::get<0>(answers[7]),
		std::get<0>(answers[8]),
		std::get<0>(answers[9])
	    );
}

void QuestionnaireDialog::collectAnswer()
{
    answers[numAnswers++] = std::make_pair(questions[current]->getValue(), questions[current]->getID());
}
void QuestionnaireDialog::setStage()
{
    if (current < NUMQUESTIONS)
    {
	if (current > 0)
	{
	    clearLayout();
	}
	qText->setText(QString::fromStdString(questions[current]->getString()));
	addHSpacer();
	questions[current]->addElements(aLayout);
	addHSpacer();
    }
}

void QuestionnaireDialog::addHSpacer()
{
    QSpacerItem * space = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    aLayout->addItem(space);
}
void QuestionnaireDialog::clearLayout()
{
    questions[current-1]->setVisible(false);
    questions[current-1]->removeElements(aLayout);

    //handle removing all remaining spacers
    while (auto item = aLayout->takeAt(0)) {
	  aLayout->removeItem(item);
    }
}

QuestionnaireDialog::~QuestionnaireDialog()
{
    //possible solutions
    //1. Remove the layout from down there v, instead ONLY add to the layouts.
	//This requires functions to both add, and remove rom
    delete ui;
}

/*######################################Question Classes######################################\\
||######################################Question Classes######################################||
\\######################################Question Classes######################################*/

/*######################################Questions######################################*/
Question::Question(std::string q, ClientAttribute i) : qString(q), id(i)
{
}
/*######################################True False Questions######################################*/
BoolQuestion::BoolQuestion(std::string q, ClientAttribute id) :
    Question(q, id)
{
    QButtonGroup * buttons = new QButtonGroup();    //functional group
    y = new QRadioButton(QString("Yes"));
    n = new QRadioButton(QString("No"));
    buttons->addButton(y);
    buttons->addButton(n);
}
int BoolQuestion::getValue()const
{
    return(y->isChecked());
}
void BoolQuestion::addElements(QLayout * layout)
{
    layout->addWidget(y);
    layout->addWidget(n);
}
void BoolQuestion::removeElements(QLayout * layout)
{
    layout->removeWidget(y);
    layout->removeWidget(n);
}
void BoolQuestion::setVisible(bool v)
{
    y->setVisible(v);
    n->setVisible(v);
}
/*######################################Large Int Questions######################################*/
LargeIntQuestion::LargeIntQuestion(std::string q, ClientAttribute id) :
    Question(q, id)
{
    valueText = new QLineEdit();
    QValidator *expValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,10}"));
    valueText->setValidator(expValidator);
}
int LargeIntQuestion::getValue()const
{
    return valueText->text().toInt();
}

void LargeIntQuestion::addElements(QLayout * layout)
{
    layout->addWidget(valueText);
}
void LargeIntQuestion::removeElements(QLayout * layout)
{
    layout->removeWidget(valueText);
}
void LargeIntQuestion::setVisible(bool v)
{
    valueText->setVisible(v);
}

/*######################################Small Int Questions######################################*/
SmallIntQuestion::SmallIntQuestion(std::string q, ClientAttribute id) :
    Question(q, id)
{
    spinBox = new QSpinBox();

    spinBox->setMaximum(999);
}
int SmallIntQuestion::getValue()const
{
    return spinBox->value();
}

void SmallIntQuestion::addElements(QLayout * layout)
{
    layout->addWidget(spinBox);
}
void SmallIntQuestion::removeElements(QLayout * layout)
{
    layout->removeWidget(spinBox);
}
void SmallIntQuestion::setVisible(bool v)
{
    spinBox->setVisible(v);
}
/*######################################Small Int Questions######################################*/
FiveLevelQuestion::FiveLevelQuestion(std::string q, ClientAttribute id) :
    Question(q, id)
{
    h = new QLabel(QString("HIGH"));
    l = new QLabel(QString("LOW"));
    slider = new QSlider(Qt::Orientation::Horizontal);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setMaximum(4);
}
int FiveLevelQuestion::getValue()const
{
    return slider->value();
}

void FiveLevelQuestion::addElements(QLayout * layout)
{
    layout->addWidget(l);
    layout->addWidget(slider);
    layout->addWidget(h);
}
void FiveLevelQuestion::removeElements(QLayout * layout)
{
    layout->removeWidget(l);
    layout->removeWidget(slider);
    layout->removeWidget(h);
}
void FiveLevelQuestion::setVisible(bool v)
{
    h->setVisible(v);
    slider->setVisible(v);
    l->setVisible(v);
}
