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

#include "Entity.h"

#define NUMQUESTIONS 10

namespace Ui {
class QuestionnaireDialog;
}
class Question;

class QuestionnaireDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionnaireDialog(Entity * target, QWidget *parent = 0);
    ~QuestionnaireDialog();


    void setQuestion(std::string  question);
private slots:
    void handleButtonClose();
    void handleButtonConfirm();

private:

    Ui::QuestionnaireDialog *ui;
    QLabel * qText;
    QLayout * aLayout;
    QPushButton * exitButton;
    QPushButton * nextButton;

    int current;
    Question ** questions;
    Entity * subject;
};

#endif // QUESTIONNAIREDIALOG_H



class Question : public QWidget
{
    Q_OBJECT
public:
    Question(std::string q, QWidget *parent=nullptr);
    Question(const Question & q) {widget = q.getWidget(); layout = q.getLayout(); qString = q.getString();}
    virtual int getValue()const=0;
    virtual QWidget* getWidget()const{return widget;}
    virtual std::string getString()const{return qString;}
    virtual QHBoxLayout * getLayout()const{return layout;}
protected:
    QWidget * widget;
    QHBoxLayout * layout;
    std::string qString;
};

class BoolQuestion : public Question
{
    Q_OBJECT
public:
    BoolQuestion(std::string q, QWidget *parent=nullptr);
    int getValue()const;
private:
    QRadioButton * y;
    QRadioButton * n;
};

class LargeIntQuestion : public Question
{
    Q_OBJECT
public:
    LargeIntQuestion (std::string q, QWidget *parent=nullptr);
    int getValue()const;
private:
    QLineEdit * valueText;
};

class SmallIntQuestion : public Question
{
    Q_OBJECT
public:
    SmallIntQuestion (std::string q, QWidget *parent=nullptr);
    int getValue()const;
private:
    QSpinBox * spinBox;
};

class FiveLevelQuestion : public Question
{
    Q_OBJECT
public:
    FiveLevelQuestion (std::string q, QWidget *parent=nullptr);
    int getValue()const;
private:
    QSlider * slider;
};
