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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDiag
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QComboBox *speciesSelector;
    QLabel *sexLabel;
    QSpinBox *ageSpinBox;
    QLineEdit *nameLineEdit;
    QTextEdit *descTextEdit;
    QLabel *speciesLabel;
    QLabel *descLabel;
    QComboBox *sexSelector;
    QLabel *ageLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *buttons;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *InputDiag)
    {
        if (InputDiag->objectName().isEmpty())
            InputDiag->setObjectName(QStringLiteral("InputDiag"));
        InputDiag->resize(341, 291);
        gridLayoutWidget = new QWidget(InputDiag);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 301, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        speciesSelector = new QComboBox(gridLayoutWidget);
        speciesSelector->setObjectName(QStringLiteral("speciesSelector"));

        gridLayout->addWidget(speciesSelector, 1, 1, 1, 1);

        sexLabel = new QLabel(gridLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        gridLayout->addWidget(sexLabel, 2, 0, 1, 1);

        ageSpinBox = new QSpinBox(gridLayoutWidget);
        ageSpinBox->setObjectName(QStringLiteral("ageSpinBox"));

        gridLayout->addWidget(ageSpinBox, 3, 1, 1, 1);

        nameLineEdit = new QLineEdit(gridLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        descTextEdit = new QTextEdit(gridLayoutWidget);
        descTextEdit->setObjectName(QStringLiteral("descTextEdit"));

        gridLayout->addWidget(descTextEdit, 4, 1, 1, 2);

        speciesLabel = new QLabel(gridLayoutWidget);
        speciesLabel->setObjectName(QStringLiteral("speciesLabel"));

        gridLayout->addWidget(speciesLabel, 1, 0, 1, 1);

        descLabel = new QLabel(gridLayoutWidget);
        descLabel->setObjectName(QStringLiteral("descLabel"));

        gridLayout->addWidget(descLabel, 4, 0, 1, 1);

        sexSelector = new QComboBox(gridLayoutWidget);
        sexSelector->setObjectName(QStringLiteral("sexSelector"));

        gridLayout->addWidget(sexSelector, 2, 1, 1, 1);

        ageLabel = new QLabel(gridLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        gridLayout->addWidget(ageLabel, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        buttons = new QWidget(InputDiag);
        buttons->setObjectName(QStringLiteral("buttons"));
        buttons->setGeometry(QRect(70, 260, 201, 31));
        saveButton = new QPushButton(buttons);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(100, 0, 89, 25));
        cancelButton = new QPushButton(buttons);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(10, 0, 89, 25));

        retranslateUi(InputDiag);

        QMetaObject::connectSlotsByName(InputDiag);
    } // setupUi

    void retranslateUi(QDialog *InputDiag)
    {
        InputDiag->setWindowTitle(QApplication::translate("InputDiag", "Animal View", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("InputDiag", "       Name:", Q_NULLPTR));
        speciesSelector->clear();
        speciesSelector->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Species", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Cat", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Dog", Q_NULLPTR)
        );
        sexLabel->setText(QApplication::translate("InputDiag", "          Sex:", Q_NULLPTR));
        speciesLabel->setText(QApplication::translate("InputDiag", "    Species:", Q_NULLPTR));
        descLabel->setText(QApplication::translate("InputDiag", "Description", Q_NULLPTR));
        sexSelector->clear();
        sexSelector->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Sex", Q_NULLPTR)
         << QApplication::translate("InputDiag", "F", Q_NULLPTR)
         << QApplication::translate("InputDiag", "M", Q_NULLPTR)
        );
        ageLabel->setText(QApplication::translate("InputDiag", "          Age:", Q_NULLPTR));
        saveButton->setText(QApplication::translate("InputDiag", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InputDiag", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDiag: public Ui_InputDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
