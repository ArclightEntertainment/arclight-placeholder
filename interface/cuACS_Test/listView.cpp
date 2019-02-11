#include "listView.h"
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
        animalList->setItem(i, 4, new QTableWidgetItem (QString::fromStdString(a[i].getSexString())));    //Sex
    }
}

ListView::~ListView()
{
    delete ui;
}
