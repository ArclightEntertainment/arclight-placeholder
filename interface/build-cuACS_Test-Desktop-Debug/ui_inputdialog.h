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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDiag
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QTabWidget *infoTabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *BasicInfo;
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
    QLabel *label;
    QLineEdit *breedLineEdit;
    QWidget *tab_2;
    QWidget *tab_3;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *buttons;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *InputDiag)
    {
        if (InputDiag->objectName().isEmpty())
            InputDiag->setObjectName(QStringLiteral("InputDiag"));
        InputDiag->resize(399, 480);
        verticalLayoutWidget = new QWidget(InputDiag);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 461));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        infoTabWidget = new QTabWidget(verticalLayoutWidget);
        infoTabWidget->setObjectName(QStringLiteral("infoTabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(infoTabWidget->sizePolicy().hasHeightForWidth());
        infoTabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 306, 252));
        BasicInfo = new QGridLayout(gridLayoutWidget);
        BasicInfo->setObjectName(QStringLiteral("BasicInfo"));
        BasicInfo->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        BasicInfo->addWidget(nameLabel, 0, 0, 1, 1);

        speciesSelector = new QComboBox(gridLayoutWidget);
        speciesSelector->setObjectName(QStringLiteral("speciesSelector"));

        BasicInfo->addWidget(speciesSelector, 1, 1, 1, 1);

        sexLabel = new QLabel(gridLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        BasicInfo->addWidget(sexLabel, 3, 0, 1, 1);

        ageSpinBox = new QSpinBox(gridLayoutWidget);
        ageSpinBox->setObjectName(QStringLiteral("ageSpinBox"));

        BasicInfo->addWidget(ageSpinBox, 5, 1, 1, 1);

        nameLineEdit = new QLineEdit(gridLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        BasicInfo->addWidget(nameLineEdit, 0, 1, 1, 1);

        descTextEdit = new QTextEdit(gridLayoutWidget);
        descTextEdit->setObjectName(QStringLiteral("descTextEdit"));

        BasicInfo->addWidget(descTextEdit, 6, 1, 1, 2);

        speciesLabel = new QLabel(gridLayoutWidget);
        speciesLabel->setObjectName(QStringLiteral("speciesLabel"));

        BasicInfo->addWidget(speciesLabel, 1, 0, 1, 1);

        descLabel = new QLabel(gridLayoutWidget);
        descLabel->setObjectName(QStringLiteral("descLabel"));

        BasicInfo->addWidget(descLabel, 6, 0, 1, 1);

        sexSelector = new QComboBox(gridLayoutWidget);
        sexSelector->setObjectName(QStringLiteral("sexSelector"));

        BasicInfo->addWidget(sexSelector, 3, 1, 1, 1);

        ageLabel = new QLabel(gridLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        BasicInfo->addWidget(ageLabel, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BasicInfo->addItem(horizontalSpacer, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        BasicInfo->addWidget(label, 2, 0, 1, 1);

        breedLineEdit = new QLineEdit(gridLayoutWidget);
        breedLineEdit->setObjectName(QStringLiteral("breedLineEdit"));

        BasicInfo->addWidget(breedLineEdit, 2, 1, 1, 1);

        infoTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        infoTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        infoTabWidget->addTab(tab_3, QString());

        layout->addWidget(infoTabWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);

        buttons = new QWidget(verticalLayoutWidget);
        buttons->setObjectName(QStringLiteral("buttons"));
        buttons->setEnabled(true);
        buttons->setMinimumSize(QSize(198, 32));
        buttons->setAutoFillBackground(false);
        saveButton = new QPushButton(buttons);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(100, 0, 89, 25));
        cancelButton = new QPushButton(buttons);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(10, 0, 89, 25));

        buttonLayout->addWidget(buttons);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_3);


        layout->addLayout(buttonLayout);

        QWidget::setTabOrder(nameLineEdit, speciesSelector);
        QWidget::setTabOrder(speciesSelector, breedLineEdit);
        QWidget::setTabOrder(breedLineEdit, sexSelector);
        QWidget::setTabOrder(sexSelector, ageSpinBox);
        QWidget::setTabOrder(ageSpinBox, descTextEdit);
        QWidget::setTabOrder(descTextEdit, saveButton);
        QWidget::setTabOrder(saveButton, cancelButton);
        QWidget::setTabOrder(cancelButton, infoTabWidget);

        retranslateUi(InputDiag);

        infoTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(InputDiag);
    } // setupUi

    void retranslateUi(QDialog *InputDiag)
    {
        InputDiag->setWindowTitle(QApplication::translate("InputDiag", "Add Animal", Q_NULLPTR));
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
        label->setText(QApplication::translate("InputDiag", "      Breed:", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tab), QApplication::translate("InputDiag", "Basic Info", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tab_2), QApplication::translate("InputDiag", "Social", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tab_3), QApplication::translate("InputDiag", "History", Q_NULLPTR));
        saveButton->setText(QApplication::translate("InputDiag", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InputDiag", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDiag: public Ui_InputDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
