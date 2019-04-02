#include "QuestionnaireDialog.h"
#include "ui_questionnairedialog.h"
#include<iostream>

QuestionnaireDialog::QuestionnaireDialog(Entity * target, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionnaireDialog),
    current(-1)
{
    ui->setupUi(this);

    subject = target;

    qText = ui->questionLabel;
    aLayout = ui->answerLayout;
    exitButton = ui->exitButton;
    nextButton = ui->nextButton;

    connect(exitButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(nextButton, SIGNAL(released()), this,SLOT(handleButtonConfirm()));

    questions = new Question*[NUMQUESTIONS];

    //years small
    questions[0] = new SmallIntQuestion(std::string("How old are you?"), this);
    //length small
    questions[1] = new SmallIntQuestion(std::string("How long do you expect to be caring for your new pet?"), this);
    //kids  bool
    questions[2] = new BoolQuestion(std::string("Are there children under the age of 12 present in your home?"), this);
    //pets bool
    questions[3] = new BoolQuestion(std::string("Is your pet likely to come in contact with other animals?"), this);
    //budget Large
    questions[4] = new LargeIntQuestion(std::string("What is your maximum monthly budget for taking care of an animal?"), this);
    //time Small
    questions[5] = new SmallIntQuestion(std::string("How many minutes per day can you devote to caring for an animal?"), this);
    //mob Five
    questions[6] = new FiveLevelQuestion(std::string("How physically mobile are you?\n(LOW = Extremely Limited, HIGH = Very Active)"), this);
    //pat Five
    questions[7] = new FiveLevelQuestion(std::string("How patient do others consider you?\n(LOW = Short Tempered, HIGH = Zen AF Fam)"), this);
    //exp Five
    questions[8] = new FiveLevelQuestion(std::string("How experienced are you with pets?\n(LOW = Never Before, HIGH = Many Years of experience)"), this);
    //aff Five
    questions[9] = new FiveLevelQuestion(std::string("How physically affectionate are you with animals?\n(LOW = Shy, HIGH = Cuddle Machine)"), this);
}
void QuestionnaireDialog::handleButtonClose()
{
    close();
}
void QuestionnaireDialog::handleButtonConfirm()
{
    current++;

    if (current > 0){
        questions[current-1]->getWidget()->setVisible(false);
        aLayout->removeWidget(questions[current-1]->getWidget());
    }
    if (current < NUMQUESTIONS)
    {
        setQuestion(questions[current]->getString());
        aLayout->addWidget(questions[current]->getWidget());
    }
    if (current == NUMQUESTIONS){
        // do stuff
        close();
    }
}


QuestionnaireDialog::~QuestionnaireDialog()
{
    delete ui;
}

void QuestionnaireDialog::setQuestion(std::string  question)
{
    qText->setText(QString::fromStdString(question));
}


/*######################################Question Classes######################################\\
||######################################Question Classes######################################||
\\######################################Question Classes######################################*/

/*######################################Questions######################################*/
Question::Question(std::string q, QWidget *parent) :
    QWidget(parent)
{
    qString = q;
    widget = new QWidget();
    layout = new QHBoxLayout();
    widget->setLayout(layout);
}
/*######################################True False Questions######################################*/
BoolQuestion::BoolQuestion(std::string q, QWidget *parent) :
    Question(q, parent)
{
    QButtonGroup * buttons = new QButtonGroup();    //functional group
    y = new QRadioButton(QString("Yes"));
    n = new QRadioButton(QString("No"));
    buttons->addButton(y);
    buttons->addButton(n);
    QSpacerItem * hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    layout->addItem(hSpacer);
    layout->addWidget(y);
    layout->addWidget(n);
    layout->addItem(hSpacer);
}
int BoolQuestion::getValue()const
{
    return(y->isChecked());
}


/*######################################Large Int Questions######################################*/
LargeIntQuestion::LargeIntQuestion(std::string q, QWidget *parent) :
    Question(q, parent)
{
    QSpacerItem * hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    valueText = new QLineEdit();
    QValidator *expValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,3}"), this);
    valueText->setValidator(expValidator);

    layout->addItem(hSpacer);
    layout->addWidget(valueText);
    layout->addItem(hSpacer);
}
int LargeIntQuestion::getValue()const
{
    return valueText->text().toInt();
}


/*######################################Small Int Questions######################################*/
SmallIntQuestion::SmallIntQuestion(std::string q, QWidget *parent) :
    Question(q, parent)
{
    QSpacerItem * hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    spinBox = new QSpinBox();

    spinBox->setMaximum(50);

    layout->addItem(hSpacer);
    layout->addWidget(spinBox);
    layout->addItem(hSpacer);
}
int SmallIntQuestion::getValue()const
{
    return spinBox->value();
}


/*######################################Small Int Questions######################################*/
FiveLevelQuestion::FiveLevelQuestion(std::string q, QWidget *parent) :
    Question(q, parent)
{
    QSpacerItem * hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    slider = new QSlider(Qt::Orientation::Horizontal);
    slider->setTickPosition(QSlider::TicksAbove);

    slider->setMaximum(4);

    layout->addItem(hSpacer);
    layout->addWidget(new QLabel(QString("LOW")));
    layout->addWidget(slider);
    layout->addWidget(new QLabel(QString("HIGH")));
    layout->addItem(hSpacer);
}
int FiveLevelQuestion::getValue()const
{
    return slider->value();
}
