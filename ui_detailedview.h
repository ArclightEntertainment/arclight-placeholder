/********************************************************************************
** Form generated from reading UI file 'detailedview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDVIEW_H
#define UI_DETAILEDVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDiag
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *detailedViewLayout;
    QHBoxLayout *acmInfoLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *nameIDLayout;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QLineEdit *idLineEdit;
    QHBoxLayout *speciesBreedLayout;
    QLineEdit *speciesLineEdit;
    QLabel *label_3;
    QLineEdit *breedLineEdit;
    QHBoxLayout *sexAgeLayout;
    QComboBox *sexComboBox;
    QLabel *label_2;
    QSpinBox *ageSpinBox;
    QLabel *ageText;
    QHBoxLayout *careLevelLayout;
    QComboBox *careLevelComboBox;
    QLabel *careLevelText;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *sliderLayout;
    QSlider *horizontalSlider_3;
    QLabel *timeCommitmentLabel;
    QLabel *adultAffinityLabel;
    QSlider *horizontalSlider_5;
    QLabel *approachabilityLabel;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_6;
    QLabel *animalAffinityLabel;
    QLabel *trainabilityLevelLabel;
    QSlider *trainabilitySlider;
    QLabel *trainingLevelLabel;
    QLabel *childAffinityLabel;
    QSlider *horizontalSlider_4;
    QSlider *trainingLevelSlider;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QComboBox *comboBox_7;
    QVBoxLayout *textBoxLayout;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InputDiag)
    {
        if (InputDiag->objectName().isEmpty())
            InputDiag->setObjectName(QStringLiteral("InputDiag"));
        InputDiag->resize(501, 516);
        verticalLayoutWidget = new QWidget(InputDiag);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 502, 491));
        detailedViewLayout = new QVBoxLayout(verticalLayoutWidget);
        detailedViewLayout->setObjectName(QStringLiteral("detailedViewLayout"));
        detailedViewLayout->setContentsMargins(0, 0, 0, 0);
        acmInfoLayout = new QHBoxLayout();
        acmInfoLayout->setObjectName(QStringLiteral("acmInfoLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameIDLayout = new QHBoxLayout();
        nameIDLayout->setObjectName(QStringLiteral("nameIDLayout"));
        nameLineEdit = new QLineEdit(verticalLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        nameIDLayout->addWidget(nameLineEdit);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(10, 16777215));

        nameIDLayout->addWidget(label);

        idLineEdit = new QLineEdit(verticalLayoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setMaximumSize(QSize(80, 16777215));

        nameIDLayout->addWidget(idLineEdit);


        verticalLayout->addLayout(nameIDLayout);

        speciesBreedLayout = new QHBoxLayout();
        speciesBreedLayout->setObjectName(QStringLiteral("speciesBreedLayout"));
        speciesLineEdit = new QLineEdit(verticalLayoutWidget);
        speciesLineEdit->setObjectName(QStringLiteral("speciesLineEdit"));

        speciesBreedLayout->addWidget(speciesLineEdit);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(10, 16777215));

        speciesBreedLayout->addWidget(label_3);

        breedLineEdit = new QLineEdit(verticalLayoutWidget);
        breedLineEdit->setObjectName(QStringLiteral("breedLineEdit"));

        speciesBreedLayout->addWidget(breedLineEdit);


        verticalLayout->addLayout(speciesBreedLayout);

        sexAgeLayout = new QHBoxLayout();
        sexAgeLayout->setObjectName(QStringLiteral("sexAgeLayout"));
        sexComboBox = new QComboBox(verticalLayoutWidget);
        sexComboBox->setObjectName(QStringLiteral("sexComboBox"));

        sexAgeLayout->addWidget(sexComboBox);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(10, 16777215));

        sexAgeLayout->addWidget(label_2);

        ageSpinBox = new QSpinBox(verticalLayoutWidget);
        ageSpinBox->setObjectName(QStringLiteral("ageSpinBox"));

        sexAgeLayout->addWidget(ageSpinBox);

        ageText = new QLabel(verticalLayoutWidget);
        ageText->setObjectName(QStringLiteral("ageText"));

        sexAgeLayout->addWidget(ageText);


        verticalLayout->addLayout(sexAgeLayout);

        careLevelLayout = new QHBoxLayout();
        careLevelLayout->setObjectName(QStringLiteral("careLevelLayout"));
        careLevelComboBox = new QComboBox(verticalLayoutWidget);
        careLevelComboBox->setObjectName(QStringLiteral("careLevelComboBox"));

        careLevelLayout->addWidget(careLevelComboBox);

        careLevelText = new QLabel(verticalLayoutWidget);
        careLevelText->setObjectName(QStringLiteral("careLevelText"));

        careLevelLayout->addWidget(careLevelText);


        verticalLayout->addLayout(careLevelLayout);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        acmInfoLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(1, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        acmInfoLayout->addItem(horizontalSpacer_3);

        sliderLayout = new QGridLayout();
        sliderLayout->setObjectName(QStringLiteral("sliderLayout"));
        horizontalSlider_3 = new QSlider(verticalLayoutWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(horizontalSlider_3, 2, 1, 1, 1);

        timeCommitmentLabel = new QLabel(verticalLayoutWidget);
        timeCommitmentLabel->setObjectName(QStringLiteral("timeCommitmentLabel"));

        sliderLayout->addWidget(timeCommitmentLabel, 6, 0, 1, 1);

        adultAffinityLabel = new QLabel(verticalLayoutWidget);
        adultAffinityLabel->setObjectName(QStringLiteral("adultAffinityLabel"));

        sliderLayout->addWidget(adultAffinityLabel, 2, 0, 1, 1);

        horizontalSlider_5 = new QSlider(verticalLayoutWidget);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(horizontalSlider_5, 4, 1, 1, 1);

        approachabilityLabel = new QLabel(verticalLayoutWidget);
        approachabilityLabel->setObjectName(QStringLiteral("approachabilityLabel"));

        sliderLayout->addWidget(approachabilityLabel, 5, 0, 1, 1);

        horizontalSlider_7 = new QSlider(verticalLayoutWidget);
        horizontalSlider_7->setObjectName(QStringLiteral("horizontalSlider_7"));
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(horizontalSlider_7, 6, 1, 1, 1);

        horizontalSlider_6 = new QSlider(verticalLayoutWidget);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(horizontalSlider_6, 5, 1, 1, 1);

        animalAffinityLabel = new QLabel(verticalLayoutWidget);
        animalAffinityLabel->setObjectName(QStringLiteral("animalAffinityLabel"));

        sliderLayout->addWidget(animalAffinityLabel, 4, 0, 1, 1);

        trainabilityLevelLabel = new QLabel(verticalLayoutWidget);
        trainabilityLevelLabel->setObjectName(QStringLiteral("trainabilityLevelLabel"));

        sliderLayout->addWidget(trainabilityLevelLabel, 1, 0, 1, 1);

        trainabilitySlider = new QSlider(verticalLayoutWidget);
        trainabilitySlider->setObjectName(QStringLiteral("trainabilitySlider"));
        trainabilitySlider->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(trainabilitySlider, 1, 1, 1, 1);

        trainingLevelLabel = new QLabel(verticalLayoutWidget);
        trainingLevelLabel->setObjectName(QStringLiteral("trainingLevelLabel"));

        sliderLayout->addWidget(trainingLevelLabel, 0, 0, 1, 1);

        childAffinityLabel = new QLabel(verticalLayoutWidget);
        childAffinityLabel->setObjectName(QStringLiteral("childAffinityLabel"));

        sliderLayout->addWidget(childAffinityLabel, 3, 0, 1, 1);

        horizontalSlider_4 = new QSlider(verticalLayoutWidget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(horizontalSlider_4, 3, 1, 1, 1);

        trainingLevelSlider = new QSlider(verticalLayoutWidget);
        trainingLevelSlider->setObjectName(QStringLiteral("trainingLevelSlider"));
        trainingLevelSlider->setOrientation(Qt::Horizontal);

        sliderLayout->addWidget(trainingLevelSlider, 0, 1, 1, 1);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        sliderLayout->addWidget(comboBox, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        sliderLayout->addWidget(comboBox_2, 1, 2, 1, 1);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        sliderLayout->addWidget(comboBox_3, 2, 2, 1, 1);

        comboBox_4 = new QComboBox(verticalLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        sliderLayout->addWidget(comboBox_4, 3, 2, 1, 1);

        comboBox_5 = new QComboBox(verticalLayoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        sliderLayout->addWidget(comboBox_5, 4, 2, 1, 1);

        comboBox_6 = new QComboBox(verticalLayoutWidget);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        sliderLayout->addWidget(comboBox_6, 5, 2, 1, 1);

        comboBox_7 = new QComboBox(verticalLayoutWidget);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setFocusPolicy(Qt::NoFocus);

        sliderLayout->addWidget(comboBox_7, 6, 2, 1, 1);


        acmInfoLayout->addLayout(sliderLayout);


        detailedViewLayout->addLayout(acmInfoLayout);

        textBoxLayout = new QVBoxLayout();
        textBoxLayout->setObjectName(QStringLiteral("textBoxLayout"));

        detailedViewLayout->addLayout(textBoxLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        buttonLayout->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        detailedViewLayout->addLayout(buttonLayout);


        retranslateUi(InputDiag);

        QMetaObject::connectSlotsByName(InputDiag);
    } // setupUi

    void retranslateUi(QDialog *InputDiag)
    {
        InputDiag->setWindowTitle(QApplication::translate("InputDiag", "Add Animal", Q_NULLPTR));
        label->setText(QApplication::translate("InputDiag", ", ", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputDiag", ", ", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputDiag", ", ", Q_NULLPTR));
        ageText->setText(QApplication::translate("InputDiag", "years old", Q_NULLPTR));
        careLevelText->setText(QApplication::translate("InputDiag", " level of care required", Q_NULLPTR));
        timeCommitmentLabel->setText(QApplication::translate("InputDiag", "Time Commitment: ", Q_NULLPTR));
        adultAffinityLabel->setText(QApplication::translate("InputDiag", "Affinity, Adults:", Q_NULLPTR));
        approachabilityLabel->setText(QApplication::translate("InputDiag", "Approachability: ", Q_NULLPTR));
        animalAffinityLabel->setText(QApplication::translate("InputDiag", "Affinity, Animals: ", Q_NULLPTR));
        trainabilityLevelLabel->setText(QApplication::translate("InputDiag", "Trainability: ", Q_NULLPTR));
        trainingLevelLabel->setText(QApplication::translate("InputDiag", "Training Level: ", Q_NULLPTR));
        childAffinityLabel->setText(QApplication::translate("InputDiag", "Affinity, Children: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDiag: public Ui_InputDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDVIEW_H
