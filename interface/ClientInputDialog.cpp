#include "ClientInputDialog.h"
#include "ui_clientinputdialog.h"

ClientInputDialog::ClientInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientInputDialog)
{
    ui->setupUi(this);
}

ClientInputDialog::~ClientInputDialog()
{
    delete ui;
}
