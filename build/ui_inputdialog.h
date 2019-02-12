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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QWidget *basic;
    QWidget *gridLayoutWidget;
    QGridLayout *BasicInfo;
    QLabel *sexLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_6;
    QSpinBox *ageSpinBox;
    QSpacerItem *verticalSpacer;
    QLabel *speciesLabel;
    QTextEdit *descTextEdit;
    QLabel *nameLabel;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QLabel *descLabel;
    QLabel *ageLabel;
    QComboBox *sexSelector;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QLineEdit *breedLineEdit;
    QLineEdit *nameLineEdit;
    QComboBox *speciesSelector;
    QSpacerItem *verticalSpacer_7;
    QFrame *line;
    QSpacerItem *verticalSpacer_4;
    QLabel *careLabel;
    QSlider *careSlider;
    QWidget *social;
    QWidget *gridLayoutWidget_2;
    QGridLayout *SocialInfo;
    QLabel *animalLabel;
    QLabel *childLabel;
    QLabel *peopleLabel;
    QLabel *trainingLabel;
    QLabel *timeLabel;
    QLabel *approachabilityLabel;
    QSlider *trainingSlider;
    QSlider *peopleSlider;
    QSlider *childSlider;
    QSlider *animalSlider;
    QSlider *approachabilitySlider;
    QSlider *timeSlider;
    QWidget *history;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout;
    QLabel *specNeedsLabel;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *immunizedLayout;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *immunizedCheckbox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *immunizedLabel;
    QLabel *aHistLabel;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *dietLineEdit;
    QLabel *label_3;
    QLineEdit *mobilityLineEdit;
    QLabel *label_4;
    QLineEdit *disabLineEdit;
    QLabel *bioLabel;
    QTextEdit *bioTextEdit;
    QTextEdit *aHistTextEdit;
    QSpacerItem *verticalSpacer_9;
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
        InputDiag->resize(501, 516);
        verticalLayoutWidget = new QWidget(InputDiag);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 481, 501));
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
        basic = new QWidget();
        basic->setObjectName(QStringLiteral("basic"));
        gridLayoutWidget = new QWidget(basic);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 411, 361));
        BasicInfo = new QGridLayout(gridLayoutWidget);
        BasicInfo->setObjectName(QStringLiteral("BasicInfo"));
        BasicInfo->setContentsMargins(0, 0, 0, 0);
        sexLabel = new QLabel(gridLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        BasicInfo->addWidget(sexLabel, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_6, 14, 1, 1, 1);

        ageSpinBox = new QSpinBox(gridLayoutWidget);
        ageSpinBox->setObjectName(QStringLiteral("ageSpinBox"));

        BasicInfo->addWidget(ageSpinBox, 8, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer, 1, 1, 1, 1);

        speciesLabel = new QLabel(gridLayoutWidget);
        speciesLabel->setObjectName(QStringLiteral("speciesLabel"));

        BasicInfo->addWidget(speciesLabel, 2, 0, 1, 1);

        descTextEdit = new QTextEdit(gridLayoutWidget);
        descTextEdit->setObjectName(QStringLiteral("descTextEdit"));

        BasicInfo->addWidget(descTextEdit, 13, 1, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        BasicInfo->addWidget(nameLabel, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_5, 10, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BasicInfo->addItem(horizontalSpacer, 0, 2, 1, 1);

        descLabel = new QLabel(gridLayoutWidget);
        descLabel->setObjectName(QStringLiteral("descLabel"));

        BasicInfo->addWidget(descLabel, 13, 0, 1, 1);

        ageLabel = new QLabel(gridLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        BasicInfo->addWidget(ageLabel, 8, 0, 1, 1);

        sexSelector = new QComboBox(gridLayoutWidget);
        sexSelector->setObjectName(QStringLiteral("sexSelector"));

        BasicInfo->addWidget(sexSelector, 6, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_3, 5, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        BasicInfo->addWidget(label, 4, 0, 1, 1);

        breedLineEdit = new QLineEdit(gridLayoutWidget);
        breedLineEdit->setObjectName(QStringLiteral("breedLineEdit"));

        BasicInfo->addWidget(breedLineEdit, 4, 1, 1, 1);

        nameLineEdit = new QLineEdit(gridLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        BasicInfo->addWidget(nameLineEdit, 0, 1, 1, 1);

        speciesSelector = new QComboBox(gridLayoutWidget);
        speciesSelector->setObjectName(QStringLiteral("speciesSelector"));

        BasicInfo->addWidget(speciesSelector, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_7, 12, 1, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        BasicInfo->addWidget(line, 11, 0, 1, 3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        BasicInfo->addItem(verticalSpacer_4, 7, 1, 1, 1);

        careLabel = new QLabel(gridLayoutWidget);
        careLabel->setObjectName(QStringLiteral("careLabel"));

        BasicInfo->addWidget(careLabel, 9, 0, 1, 1);

        careSlider = new QSlider(gridLayoutWidget);
        careSlider->setObjectName(QStringLiteral("careSlider"));
        careSlider->setMaximum(2);
        careSlider->setSliderPosition(1);
        careSlider->setOrientation(Qt::Horizontal);

        BasicInfo->addWidget(careSlider, 9, 1, 1, 1);

        infoTabWidget->addTab(basic, QString());
        social = new QWidget();
        social->setObjectName(QStringLiteral("social"));
        gridLayoutWidget_2 = new QWidget(social);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 30, 411, 371));
        SocialInfo = new QGridLayout(gridLayoutWidget_2);
        SocialInfo->setObjectName(QStringLiteral("SocialInfo"));
        SocialInfo->setContentsMargins(0, 0, 0, 0);
        animalLabel = new QLabel(gridLayoutWidget_2);
        animalLabel->setObjectName(QStringLiteral("animalLabel"));

        SocialInfo->addWidget(animalLabel, 3, 0, 1, 1);

        childLabel = new QLabel(gridLayoutWidget_2);
        childLabel->setObjectName(QStringLiteral("childLabel"));

        SocialInfo->addWidget(childLabel, 2, 0, 1, 1);

        peopleLabel = new QLabel(gridLayoutWidget_2);
        peopleLabel->setObjectName(QStringLiteral("peopleLabel"));

        SocialInfo->addWidget(peopleLabel, 1, 0, 1, 1);

        trainingLabel = new QLabel(gridLayoutWidget_2);
        trainingLabel->setObjectName(QStringLiteral("trainingLabel"));

        SocialInfo->addWidget(trainingLabel, 0, 0, 1, 1);

        timeLabel = new QLabel(gridLayoutWidget_2);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        SocialInfo->addWidget(timeLabel, 5, 0, 1, 1);

        approachabilityLabel = new QLabel(gridLayoutWidget_2);
        approachabilityLabel->setObjectName(QStringLiteral("approachabilityLabel"));

        SocialInfo->addWidget(approachabilityLabel, 4, 0, 1, 1);

        trainingSlider = new QSlider(gridLayoutWidget_2);
        trainingSlider->setObjectName(QStringLiteral("trainingSlider"));
        trainingSlider->setMaximum(2);
        trainingSlider->setSliderPosition(1);
        trainingSlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(trainingSlider, 0, 1, 1, 1);

        peopleSlider = new QSlider(gridLayoutWidget_2);
        peopleSlider->setObjectName(QStringLiteral("peopleSlider"));
        peopleSlider->setMaximum(2);
        peopleSlider->setSliderPosition(1);
        peopleSlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(peopleSlider, 1, 1, 1, 1);

        childSlider = new QSlider(gridLayoutWidget_2);
        childSlider->setObjectName(QStringLiteral("childSlider"));
        childSlider->setMaximum(2);
        childSlider->setSliderPosition(1);
        childSlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(childSlider, 2, 1, 1, 1);

        animalSlider = new QSlider(gridLayoutWidget_2);
        animalSlider->setObjectName(QStringLiteral("animalSlider"));
        animalSlider->setMaximum(2);
        animalSlider->setSliderPosition(1);
        animalSlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(animalSlider, 3, 1, 1, 1);

        approachabilitySlider = new QSlider(gridLayoutWidget_2);
        approachabilitySlider->setObjectName(QStringLiteral("approachabilitySlider"));
        approachabilitySlider->setMaximum(2);
        approachabilitySlider->setSliderPosition(1);
        approachabilitySlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(approachabilitySlider, 4, 1, 1, 1);

        timeSlider = new QSlider(gridLayoutWidget_2);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setMaximum(2);
        timeSlider->setSliderPosition(1);
        timeSlider->setOrientation(Qt::Horizontal);

        SocialInfo->addWidget(timeSlider, 5, 1, 1, 1);

        infoTabWidget->addTab(social, QString());
        history = new QWidget();
        history->setObjectName(QStringLiteral("history"));
        gridLayoutWidget_3 = new QWidget(history);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(30, 30, 411, 371));
        gridLayout = new QGridLayout(gridLayoutWidget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        specNeedsLabel = new QLabel(gridLayoutWidget_3);
        specNeedsLabel->setObjectName(QStringLiteral("specNeedsLabel"));

        gridLayout->addWidget(specNeedsLabel, 1, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 2, 1, 1, 1);

        immunizedLayout = new QHBoxLayout();
        immunizedLayout->setObjectName(QStringLiteral("immunizedLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        immunizedLayout->addItem(horizontalSpacer_4);

        immunizedCheckbox = new QCheckBox(gridLayoutWidget_3);
        immunizedCheckbox->setObjectName(QStringLiteral("immunizedCheckbox"));

        immunizedLayout->addWidget(immunizedCheckbox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        immunizedLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(immunizedLayout, 0, 1, 1, 1);

        immunizedLabel = new QLabel(gridLayoutWidget_3);
        immunizedLabel->setObjectName(QStringLiteral("immunizedLabel"));

        gridLayout->addWidget(immunizedLabel, 0, 0, 1, 1);

        aHistLabel = new QLabel(gridLayoutWidget_3);
        aHistLabel->setObjectName(QStringLiteral("aHistLabel"));

        gridLayout->addWidget(aHistLabel, 6, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        dietLineEdit = new QLineEdit(gridLayoutWidget_3);
        dietLineEdit->setObjectName(QStringLiteral("dietLineEdit"));
        dietLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, dietLineEdit);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        mobilityLineEdit = new QLineEdit(gridLayoutWidget_3);
        mobilityLineEdit->setObjectName(QStringLiteral("mobilityLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, mobilityLineEdit);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        disabLineEdit = new QLineEdit(gridLayoutWidget_3);
        disabLineEdit->setObjectName(QStringLiteral("disabLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, disabLineEdit);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        bioLabel = new QLabel(gridLayoutWidget_3);
        bioLabel->setObjectName(QStringLiteral("bioLabel"));

        gridLayout->addWidget(bioLabel, 4, 0, 1, 1);

        bioTextEdit = new QTextEdit(gridLayoutWidget_3);
        bioTextEdit->setObjectName(QStringLiteral("bioTextEdit"));

        gridLayout->addWidget(bioTextEdit, 4, 1, 1, 1);

        aHistTextEdit = new QTextEdit(gridLayoutWidget_3);
        aHistTextEdit->setObjectName(QStringLiteral("aHistTextEdit"));

        gridLayout->addWidget(aHistTextEdit, 6, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 5, 1, 1, 1);

        infoTabWidget->addTab(history, QString());

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
        QWidget::setTabOrder(descTextEdit, cancelButton);
        QWidget::setTabOrder(cancelButton, saveButton);
        QWidget::setTabOrder(saveButton, infoTabWidget);
        QWidget::setTabOrder(infoTabWidget, trainingSlider);
        QWidget::setTabOrder(trainingSlider, peopleSlider);
        QWidget::setTabOrder(peopleSlider, childSlider);
        QWidget::setTabOrder(childSlider, animalSlider);
        QWidget::setTabOrder(animalSlider, approachabilitySlider);
        QWidget::setTabOrder(approachabilitySlider, timeSlider);

        retranslateUi(InputDiag);

        infoTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InputDiag);
    } // setupUi

    void retranslateUi(QDialog *InputDiag)
    {
        InputDiag->setWindowTitle(QApplication::translate("InputDiag", "Add Animal", Q_NULLPTR));
        sexLabel->setText(QApplication::translate("InputDiag", "               Sex:", Q_NULLPTR));
        speciesLabel->setText(QApplication::translate("InputDiag", "        Species:", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("InputDiag", "          Name:", Q_NULLPTR));
        descLabel->setText(QApplication::translate("InputDiag", "Description", Q_NULLPTR));
        ageLabel->setText(QApplication::translate("InputDiag", "               Age:", Q_NULLPTR));
        sexSelector->clear();
        sexSelector->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Sex", Q_NULLPTR)
         << QApplication::translate("InputDiag", "F", Q_NULLPTR)
         << QApplication::translate("InputDiag", "M", Q_NULLPTR)
        );
        label->setText(QApplication::translate("InputDiag", "           Breed:", Q_NULLPTR));
        speciesSelector->clear();
        speciesSelector->insertItems(0, QStringList()
         << QApplication::translate("InputDiag", "Species", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Cat", Q_NULLPTR)
         << QApplication::translate("InputDiag", "Dog", Q_NULLPTR)
        );
        careLabel->setText(QApplication::translate("InputDiag", "Level of Care: ", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(basic), QApplication::translate("InputDiag", "Basic Info", Q_NULLPTR));
        animalLabel->setText(QApplication::translate("InputDiag", "   Affinity, Animals: ", Q_NULLPTR));
        childLabel->setText(QApplication::translate("InputDiag", "   Affinity, Children: ", Q_NULLPTR));
        peopleLabel->setText(QApplication::translate("InputDiag", "     Affinity, People: ", Q_NULLPTR));
        trainingLabel->setText(QApplication::translate("InputDiag", "                Training: ", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("InputDiag", "Time Commitment: ", Q_NULLPTR));
        approachabilityLabel->setText(QApplication::translate("InputDiag", "    Approachability: ", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(social), QApplication::translate("InputDiag", "Social", Q_NULLPTR));
        specNeedsLabel->setText(QApplication::translate("InputDiag", "   Special Needs: ", Q_NULLPTR));
        immunizedCheckbox->setText(QString());
        immunizedLabel->setText(QApplication::translate("InputDiag", "        Immunized: ", Q_NULLPTR));
        aHistLabel->setText(QApplication::translate("InputDiag", "History of Abuse: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputDiag", "Dietary: ", Q_NULLPTR));
        dietLineEdit->setText(QString());
        dietLineEdit->setPlaceholderText(QApplication::translate("InputDiag", "Dietary Restrictions", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputDiag", "Mobility: ", Q_NULLPTR));
        mobilityLineEdit->setPlaceholderText(QApplication::translate("InputDiag", "Mobility Restrictions", Q_NULLPTR));
        label_4->setText(QApplication::translate("InputDiag", "Disabilities: ", Q_NULLPTR));
        disabLineEdit->setPlaceholderText(QApplication::translate("InputDiag", "Physical Disabilities", Q_NULLPTR));
        bioLabel->setText(QApplication::translate("InputDiag", "          Biography: ", Q_NULLPTR));
        infoTabWidget->setTabText(infoTabWidget->indexOf(history), QApplication::translate("InputDiag", "History", Q_NULLPTR));
        saveButton->setText(QApplication::translate("InputDiag", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InputDiag", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDiag: public Ui_InputDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
