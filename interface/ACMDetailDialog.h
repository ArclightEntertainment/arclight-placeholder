#ifndef ACMDETAILDIALOG_H
#define ACMDETAILDIALOG_H

#include <QDialog>

namespace Ui {
class ACMDetailDialog;
}

class ACMDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ACMDetailDialog(QWidget *parent = 0);
    ~ACMDetailDialog();

private:
    Ui::ACMDetailDialog *ui;
};

#endif // ACMDETAILDIALOG_H
