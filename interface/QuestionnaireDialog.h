#ifndef QUESTIONNAIREDIALOG_H
#define QUESTIONNAIREDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QSpacerItem>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QSlider>
#include <QComboBox>
#include <QLayout>


namespace Ui {
class QuestionnaireDialog;
}

class QuestionnaireDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionnaireDialog(QWidget *parent = 0);
    ~QuestionnaireDialog();


    void setQuestion(std::string  question);
    void test();
private slots:
    void handleButtonClose();
    void handleButtonConfirm();

private:
    Ui::QuestionnaireDialog *ui;
    QLabel * qText;
    QLayout * aLayout;
    QPushButton * exitButton;
    QPushButton * nextButton;
};

#endif // QUESTIONNAIREDIALOG_H



class IntQuestion : public QWidget
{
    Q_OBJECT
public:
    IntQuestion(QWidget *parent=nullptr);
    virtual int getValue()=0;
    virtual QWidget* getWidget(){return widget;}
protected:
    QWidget * widget;
    QHBoxLayout * layout;
};



class TFQuestion : public IntQuestion
{
    Q_OBJECT
public:
    TFQuestion(QWidget *parent=nullptr);
    int getValue();
private:
    QRadioButton * y;
    QRadioButton * n;
};
