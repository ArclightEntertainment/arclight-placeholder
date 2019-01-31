/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *descLabel;
    QLabel *diagLabel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *speciesLabel;
    QLineEdit *speciesLineEdit;
    QLabel *sexLabel;
    QLineEdit *sexLineEdit;
    QLabel *ageLabel;
    QLineEdit *ageLineEdit;
    QTextEdit *descTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 260, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        descLabel = new QLabel(Dialog);
        descLabel->setObjectName(QStringLiteral("descLabel"));
        descLabel->setGeometry(QRect(10, 170, 80, 17));
        diagLabel = new QLabel(Dialog);
        diagLabel->setObjectName(QStringLiteral("diagLabel"));
        diagLabel->setGeometry(QRect(10, 10, 91, 17));
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 39, 381, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        speciesLabel = new QLabel(formLayoutWidget);
        speciesLabel->setObjectName(QStringLiteral("speciesLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, speciesLabel);

        speciesLineEdit = new QLineEdit(formLayoutWidget);
        speciesLineEdit->setObjectName(QStringLiteral("speciesLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, speciesLineEdit);

        sexLabel = new QLabel(formLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sexLabel);

        sexLineEdit = new QLineEdit(formLayoutWidget);
        sexLineEdit->setObjectName(QStringLiteral("sexLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sexLineEdit);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ageLabel);

        ageLineEdit = new QLineEdit(formLayoutWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ageLineEdit);

        descTextEdit = new QTextEdit(Dialog);
        descTextEdit->setObjectName(QStringLiteral("descTextEdit"));
        descTextEdit->setGeometry(QRect(90, 170, 291, 91));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        descLabel->setText(QApplication::translate("Dialog", "Description", Q_NULLPTR));
        diagLabel->setText(QApplication::translate("Dialog", "Add New Pet", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("Dialog", "Name", Q_NULLPTR));
        speciesLabel->setText(QApplication::translate("Dialog", "Species", Q_NULLPTR));
        sexLabel->setText(QApplication::translate("Dialog", "Sex", Q_NULLPTR));
        ageLabel->setText(QApplication::translate("Dialog", "Age", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
