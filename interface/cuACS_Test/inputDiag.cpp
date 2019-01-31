#include "inputDiag.h"
#include "ui_inputdialog.h"

InputDiag::InputDiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDiag)
{
    ui->setupUi(this);
}

InputDiag::~InputDiag()
{
    delete ui;
}
