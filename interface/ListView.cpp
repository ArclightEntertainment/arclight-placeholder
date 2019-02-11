#include "ListView.h"
#include "ui_listview.h"
#include <iostream>

ListView::ListView(AnimalManager *aM, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    animalList = ui->animalTableWidget;
    manager = aM;

    updateListView();
}

void ListView::updateListView()
{
    std::cout<< manager->getNumAnimals() << std::endl;
    animalList->setRowCount(manager->getNumAnimals());

    QStringList columnNames = {"Name", "Species", "Breed", "Age", "Sex"};
    animalList->setColumnCount(columnNames.length());
    animalList->setHorizontalHeaderLabels(columnNames);

    Animal *a = manager->getAnimalCollection();

    for(int i = 0; i < manager->getNumAnimals(); i++)
    {
        animalList->setItem(i, 0, new QTableWidgetItem (QString::fromStdString(a[i].getName())));    //Name
        animalList->setItem(i, 1, new QTableWidgetItem (QString::fromStdString(a[i].getSpecies())));    //Species
        animalList->setItem(i, 2, new QTableWidgetItem (QString::fromStdString(a[i].getBreed())));    //Breed
        animalList->setItem(i, 3, new QTableWidgetItem (QString::number(a[i].getAge())));    //Age
        animalList->setItem(i, 4, new QTableWidgetItem (QString(QChar::fromLatin1(a[i].getSex()))));    //Sex
    }
    animalList->setColumnWidth(0, 150); //Name
    animalList->setColumnWidth(1, 150); //Species
    animalList->setColumnWidth(2, 100); //Breed
    animalList->setColumnWidth(3, 50); //Age
    animalList->setColumnWidth(4, 48); //Sex
    animalList->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

ListView::~ListView()
{
    delete ui;
}
