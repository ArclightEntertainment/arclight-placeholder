/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDiag
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *speciesLabel;
    QLabel *sexLabel;
    QLabel *ageLabel;
    QLineEdit *ageLineEdit;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *descLabel;
    QTextEdit *descTextEdit;

    void setupUi(QDialog *InputDiag)
    {
        if (InputDiag->objectName().isEmpty())
            InputDiag->setObjectName(QStringLiteral("InputDiag"));
        InputDiag->resize(400, 300);
        buttonBox = new QDialogButtonBox(InputDiag);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 260, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(InputDiag);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 29, 381, 121));
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

        sexLabel = new QLabel(formLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sexLabel);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ageLabel);

        ageLineEdit = new QLineEdit(formLayoutWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ageLineEdit);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_2);

        descLabel = new QLabel(InputDiag);
        descLabel->setObjectName(QStringLiteral("descLabel"));
        descLabel->setGeometry(QRect(10, 160, 80, 17));
        descTextEdit = new QTextEdit(InputDiag);
        descTextEdit->setObjectName(QStringLiteral("descTextEdit"));
        descTextEdit->setGeometry(QRect(90, 160, 291, 91));
        QWidget::setTabOrder(nameLineEdit, comboBox);
        QWidget::setTabOrder(comboBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, ageLineEdit);
        QWidget::setTabOrder(ageLineEdit, descTextEdit);

        retranslateUi(InputDiag);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputDiag, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputDiag, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputDiag);
    } // setupUi

    void retranslateUi(QDialog *InputDiag)
    {
        InputDiag->setWindowTitle(QApplication::translate("InputDiag", "Dialog", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("InputDiag", "Name", Q_NULLPTR));
        speciesLabel->setText(QApplication::translate("InputDiag", "Species", Q_NULLPTR));
        sexLabel->setText(QApplication::translate("InputDiag", "Sex", Q_NULLPTR));
        ageLabel->setText(QApplication::translate("InputDiag", "Age", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Species", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Cat", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Dog", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Sex", Q_NULLPTR)
         << QApplication::translate("InputDiag", "F", Q_NULLPTR)
         << QApplication::translate("InputDiag", "M", Q_NULLPTR)
        );
        descLabel->setText(QApplication::translate("InputDiag", "Description", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDiag: public Ui_InputDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
