#include "QuestionnaireDialog.h"
#include "ui_questionnairedialog.h"
#include<iostream>

QuestionnaireDialog::QuestionnaireDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionnaireDialog)
{
    ui->setupUi(this);
    qText = ui->questionLabel;
    aLayout = ui->answerLayout;
    exitButton = ui->exitButton;
    nextButton = ui->nextButton;

    connect(exitButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(nextButton, SIGNAL(released()), this,SLOT(handleButtonConfirm()));

    test();
}
void QuestionnaireDialog::handleButtonClose()
{
    close();
}
void QuestionnaireDialog::handleButtonConfirm()
{
}

QuestionnaireDialog::~QuestionnaireDialog()
{
    delete ui;
}

void QuestionnaireDialog::setQuestion(std::string  question)
{
    qText->setText(QString::fromStdString(question));
}


void QuestionnaireDialog::test()
{
    setQuestion("Are there children under the age of 12 present in your home");
    TFQuestion * q = new TFQuestion();
    aLayout->addWidget(q->getWidget());
}

/*######################################Question Classes######################################\\
||######################################Question Classes######################################||
\\######################################Question Classes######################################*/

IntQuestion::IntQuestion(QWidget *parent) :
    QWidget(parent)
{
    widget = new QWidget();
    layout = new QHBoxLayout();
    widget->setLayout(layout);
}
TFQuestion::TFQuestion(QWidget *parent) :
    IntQuestion(parent)
{
    QButtonGroup * buttons = new QButtonGroup();    //functional group
    QRadioButton * yButton = new QRadioButton(QString("Yes"));
    QRadioButton * nButton = new QRadioButton(QString("No"));
    buttons->addButton(yButton);
    buttons->addButton(nButton);
    QSpacerItem * hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    layout->addItem(hSpacer);
    layout->addWidget(yButton);
    layout->addWidget(nButton);
    layout->addItem(hSpacer);
}
int TFQuestion::getValue()
{

}
