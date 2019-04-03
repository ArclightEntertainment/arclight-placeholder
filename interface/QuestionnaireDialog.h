#ifndef QUESTIONNAIREDIALOG_H
#define QUESTIONNAIREDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QSpacerItem>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QLayout>
#include <qstring.h>

#include <utility>

#include "CUACSController.h"

#define NUMQUESTIONS 10

namespace Ui {
class QuestionnaireDialog;
}
class Question;

class QuestionnaireDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionnaireDialog(CUACSController *med, Entity * target, QWidget *parent = 0);
    ~QuestionnaireDialog();

private slots:
    void handleButtonClose();
    void handleButtonConfirm();

private:
    void setStage();
    void clearLayout();
    void addHSpacer();
    void collectAnswer();

    Ui::QuestionnaireDialog *ui;
    QLabel * qText;
    QLayout * aLayout;
    QPushButton * exitButton;
    QPushButton * nextButton;

    int current;
    Question ** questions;
    std::pair<int, int> * answers;
    int numAnswers;

    Entity * subject;
    CUACSController * mediator;
};

#endif // QUESTIONNAIREDIALOG_H



class Question
{
public:
    Question(std::string q, int id);
    virtual int getValue()const=0;
    virtual int getID() const {return id;}
    virtual std::string getString()const{return qString;}
    virtual void addElements(QLayout * layout)=0;
    virtual void setVisible(bool v)=0;
protected:
    std::string qString;
    int id;
};

class BoolQuestion : public Question
{
public:
    BoolQuestion(std::string q, int id);
    int getValue()const;
    virtual void addElements(QLayout * layout);
    virtual void setVisible(bool v);
private:
    QRadioButton * y;
    QRadioButton * n;
};

class LargeIntQuestion : public Question
{
public:
    LargeIntQuestion (std::string q, int id);
    int getValue()const;
    virtual void addElements(QLayout * layout);
    virtual void setVisible(bool v);
private:
    QLineEdit * valueText;
};

class SmallIntQuestion : public Question
{
public:
    SmallIntQuestion (std::string q, int id);
    int getValue()const;
    virtual void addElements(QLayout * layout);
    virtual void setVisible(bool v);
private:
    QSpinBox * spinBox;
};

class FiveLevelQuestion : public Question
{
public:
    FiveLevelQuestion (std::string q, int id);
    int getValue()const;
    virtual void addElements(QLayout * layout);
    virtual void setVisible(bool v);
private:
    QSlider * slider;
    QLabel * h;
    QLabel * l;
};
