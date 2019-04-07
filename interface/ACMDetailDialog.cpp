#include "ACMDetailDialog.h"
#include "ui_acmdetaildialog.h"

ACMDetailDialog::ACMDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMDetailDialog)
{
    ui->setupUi(this);
}

ACMDetailDialog::~ACMDetailDialog()
{
    delete ui;
}
