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
    int id = animalList->item(currentIndex.row(), animalList->columnCount()-1)->text().toInt();
    AnimalDetailDiag diag(manager, manager->getAnimalWithId(id), false, this);
    diag.setWindowTitle(QString::fromStdString(manager->getAnimalWithId(id)->getName() + " Profile"));
    diag.exec();
}

//Update the ListView, inserts all values
void AnimalListView::updateListView()
{
    animalList->setRowCount(manager->getNumAnimals());

    QStringList columnNames = {"Name", "Species", "Breed", "Age", "Sex", "ID"};
    animalList->setColumnCount(columnNames.length());
    animalList->setHorizontalHeaderLabels(columnNames);

    Animal *a = manager->getAnimalCollection();
    for(int i = 0; i < manager->getNumAnimals(); i++)
    {
        //Create item widgets for row
        MyTableWidgetItem *name = new MyTableWidgetItem (QString::fromStdString(a[i].getName()));
        MyTableWidgetItem *species = new MyTableWidgetItem (QString::fromStdString(a[i].getSpecies()));
        MyTableWidgetItem *breed = new MyTableWidgetItem (QString::fromStdString(a[i].getBreed()));
        MyTableWidgetItem *age = new MyTableWidgetItem (QString::number(a[i].getAge()));
        MyTableWidgetItem *sex = new MyTableWidgetItem (QString(QChar::fromLatin1(a[i].getSex())));
        MyTableWidgetItem *id = new MyTableWidgetItem (QString::number(a[i].getShelterID()));
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
    //int arr [6] = {120, 120, 106, 56, 42, 42};
    animalList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    animalList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //sort ascending
    animalList->sortByColumn(animalList->columnCount()-1, Qt::SortOrder::AscendingOrder);
}

//destructor
AnimalListView::~AnimalListView()
{
    delete ui;
}
