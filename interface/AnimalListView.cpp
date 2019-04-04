#include "AnimalListView.h"
#include "ui_listview.h"
#include <iostream>

//Constructor, requires QWidget and an Animalmediator
AnimalListView::AnimalListView(CUACSController *med, QWidget *parent) :
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

    mediator = med;

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
    AnimalDetailDiag diag(mediator, mediator->getAnimalWithId(id), false, this);
    diag.setWindowTitle(QString::fromStdString(mediator->getAnimalWithId(id)->getName() + " Profile"));
    diag.exec();
    updateListView();
}

//Update the ListView, inserts all values
void AnimalListView::updateListView()
{
    animalList->setRowCount(mediator->getNumEntities('a'));

    QStringList columnNames = {"Name", "Species", "Breed", "Age", "Sex", "ID"};
    animalList->setColumnCount(columnNames.length());
    animalList->setHorizontalHeaderLabels(columnNames);

    Iterator<UAnimal*> *a = mediator->createAnimalIterator();
    int i = 0;
    while(!a->isDone())
    {
        std::cout<<a->currentItem()->getName()<<std::endl;
        //Create item widgets for row
        MyTableWidgetItem *name = new MyTableWidgetItem (QString::fromStdString         (a->currentItem()->getName()));
	MyTableWidgetItem *species = new MyTableWidgetItem (QString::fromStdString      (a->currentItem()->getString(static_cast<int>(AnimalAttribute::SPECIES))));
	MyTableWidgetItem *breed = new MyTableWidgetItem (QString::fromStdString        (a->currentItem()->getString(static_cast<int>(AnimalAttribute::BREED))));
	MyTableWidgetItem *age = new MyTableWidgetItem (QString::number                 (a->currentItem()->getInt(static_cast<int>(AnimalAttribute::AGE))));
	MyTableWidgetItem *sex = new MyTableWidgetItem (QString::fromStdString          (a->currentItem()->getString(static_cast<int>(AnimalAttribute::SEX))));
        MyTableWidgetItem *id = new MyTableWidgetItem (QString::number                  (a->currentItem()->getID()));
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

        i++;
        a->next();
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
