#include "ListView.h"
#include "ui_listview.h"
#include <iostream>

ListView::ListView(AnimalManager *aM, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    animalList = ui->animalTableWidget;
    animalList->setSelectionBehavior(QAbstractItemView::SelectRows);
    animalList->setSelectionMode(QAbstractItemView::SingleSelection);
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
        QTableWidgetItem *name = new QTableWidgetItem (QString::fromStdString(a[i].getName()));
        QTableWidgetItem *species = new QTableWidgetItem (QString::fromStdString(a[i].getSpecies()));
        QTableWidgetItem *breed = new QTableWidgetItem (QString::fromStdString(a[i].getBreed()));
        QTableWidgetItem *age = new QTableWidgetItem (QString::number(a[i].getAge()));
        QTableWidgetItem *sex = new QTableWidgetItem (QString(QChar::fromLatin1(a[i].getSex())));

        name->setFlags(name->flags() ^ Qt::ItemIsEditable);
        species->setFlags(species->flags() ^ Qt::ItemIsEditable);
        breed->setFlags(breed->flags() ^ Qt::ItemIsEditable);
        age->setFlags(age->flags() ^ Qt::ItemIsEditable);
        sex->setFlags(sex->flags() ^ Qt::ItemIsEditable);

        animalList->setItem(i, 0, name);    //Name
        animalList->setItem(i, 1, species);    //Species
        animalList->setItem(i, 2, breed);    //Breed
        animalList->setItem(i, 3, age);    //Age
        animalList->setItem(i, 4, sex);    //Sex
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
