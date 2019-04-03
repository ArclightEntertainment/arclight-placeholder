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
    answers = new std::pair<int, int>[NUMQUESTIONS];
    numAnswers=0;

    questions[0] = new SmallIntQuestion(std::string("How old are you?"), 0);
    questions[1] = new SmallIntQuestion(std::string("How long do you expect to be caring for your new pet?"), 0);
    questions[2] = new BoolQuestion(std::string("Are there children under the age of 12 present in your home?"), 0);
    questions[3] = new BoolQuestion(std::string("Is your pet likely to come in contact with other animals?"), 0);
    questions[4] = new LargeIntQuestion(std::string("What is your maximum monthly budget for taking care of an animal?"), 0);
    questions[5] = new SmallIntQuestion(std::string("How many minutes per day can you devote to caring for an animal?"), 0);
    questions[6] = new FiveLevelQuestion(std::string("How physically mobile are you?\n(LOW = Extremely Limited, HIGH = Very Active)"), 0);
    questions[7] = new FiveLevelQuestion(std::string("How patient do others consider you?\n(LOW = Short Tempered, HIGH = Zen AF Fam)"), 0);
    questions[8] = new FiveLevelQuestion(std::string("How experienced are you with pets?\n(LOW = Never Before, HIGH = Many Years of experience)"), 0);
    questions[9] = new FiveLevelQuestion(std::string("How physically affectionate are you with animals?\n(LOW = Shy, HIGH = Cuddle Machine)"), 0);

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
    }
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
Question::Question(std::string q, int i) : qString(q), id(i)
{
}
/*######################################True False Questions######################################*/
BoolQuestion::BoolQuestion(std::string q, int id) :
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
void BoolQuestion::setVisible(bool v)
{
    y->setVisible(v);
    n->setVisible(v);
}
/*######################################Large Int Questions######################################*/
LargeIntQuestion::LargeIntQuestion(std::string q, int id) :
    Question(q, id)
{
    valueText = new QLineEdit();
    QValidator *expValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,3}"));
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
void LargeIntQuestion::setVisible(bool v)
{
    valueText->setVisible(v);
}

/*######################################Small Int Questions######################################*/
SmallIntQuestion::SmallIntQuestion(std::string q, int id) :
    Question(q, id)
{
    spinBox = new QSpinBox();

    spinBox->setMaximum(50);
}
int SmallIntQuestion::getValue()const
{
    return spinBox->value();
}

void SmallIntQuestion::addElements(QLayout * layout)
{
    layout->addWidget(spinBox);
}
void SmallIntQuestion::setVisible(bool v)
{
    spinBox->setVisible(v);
}
/*######################################Small Int Questions######################################*/
FiveLevelQuestion::FiveLevelQuestion(std::string q, int id) :
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
    layout->addWidget(h);
    layout->addWidget(slider);
    layout->addWidget(l);
}
void FiveLevelQuestion::setVisible(bool v)
{
    h->setVisible(v);
    slider->setVisible(v);
    l->setVisible(v);
}
