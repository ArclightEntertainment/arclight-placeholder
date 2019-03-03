#include "AnimalListView.h"
#include "ui_listview.h"
#include <iostream>

//Constructor, requires QWidget and an AnimalManager
AnimalListView::AnimalListView(AnimalManager *aM, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    detailsButton = ui->detailsButton;

    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(detailsButton, SIGNAL(released()), this,SLOT(handleButtonDetail()));

    animalList = ui->tableWidget;
    animalList->setSelectionBehavior(QAbstractItemView::SelectRows);
    animalList->setSelectionMode(QAbstractItemView::SingleSelection);

    manager = aM;

    updateListView();
}

void AnimalListView::handleButtonClose()
{
    close();
}
void AnimalListView::handleButtonDetail()

{
    QModelIndex currentIndex = animalList->currentIndex();
    std::string name = animalList->item(currentIndex.row(), 0)->text().toStdString();
    AnimalDetailDiag diag(manager, manager->getAnimalWithName(name), this);
    diag.exec();
}

//Update the ListView, inserts all values
void AnimalListView::updateListView()
{
    //std::cout<< manager->getNumAnimals() << std::endl;
    animalList->setRowCount(manager->getNumAnimals());

    QStringList columnNames = {"Name", "Species", "Breed", "Age", "Sex", "ID"};
    animalList->setColumnCount(columnNames.length());
    animalList->setHorizontalHeaderLabels(columnNames);

    Animal *a = manager->getAnimalCollection();
    for(int i = 0; i < manager->getNumAnimals(); i++)
    {
        //Create item widgets for row
        QTableWidgetItem *name = new QTableWidgetItem (QString::fromStdString(a[i].getName()));
        QTableWidgetItem *species = new QTableWidgetItem (QString::fromStdString(a[i].getSpecies()));
        QTableWidgetItem *breed = new QTableWidgetItem (QString::fromStdString(a[i].getBreed()));
        QTableWidgetItem *age = new QTableWidgetItem (QString::number(a[i].getAge()));
        QTableWidgetItem *sex = new QTableWidgetItem (QString(QChar::fromLatin1(a[i].getSex())));
        QTableWidgetItem *id = new QTableWidgetItem (QString::number(a[i].getShelterID()));
        std::cout << "AAA: " << name->text().toStdString() << " " << id->text().toInt() << std::endl;
        //set all as un-editable
        name->setFlags(name->flags() ^ Qt::ItemIsEditable);
        species->setFlags(species->flags() ^ Qt::ItemIsEditable);
        breed->setFlags(breed->flags() ^ Qt::ItemIsEditable);
        age->setFlags(age->flags() ^ Qt::ItemIsEditable);
        sex->setFlags(sex->flags() ^ Qt::ItemIsEditable);
        id->setFlags(id->flags() ^ Qt::ItemIsEditable);

        //place items into list view
        animalList->setItem(i, 0, name);    //Name
        animalList->setItem(i, 1, species);    //Species
        animalList->setItem(i, 2, breed);    //Breed
        animalList->setItem(i, 3, age);    //Age
        animalList->setItem(i, 4, sex);    //Sex
        animalList->setItem(i, 5, id);    //ShelterID
    }
    //set dimensions
    animalList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    animalList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    animalList->setColumnWidth(0, 120); //Name
    animalList->setColumnWidth(1, 120); //Species
    animalList->setColumnWidth(2, 106); //Breed
    animalList->setColumnWidth(3, 56); //Age
    animalList->setColumnWidth(4, 42); //Sex
    animalList->setColumnWidth(5, 42); //ShelterID
    //sort ascending
    animalList->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

//destructor
AnimalListView::~AnimalListView()
{
    delete ui;
}
