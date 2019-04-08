#include "ACMListView.h"
#include "ui_listview.h"
#include <iostream>
#include "ACMDetailDialog.h"

//Constructor, requires QWidget and an Animalmediator
ACMListView::ACMListView(CUACSController *med, int cID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView),
    currentID(cID)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    detailsButton = ui->detailsButton;

    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(detailsButton, SIGNAL(released()), this,SLOT(handleButtonDetail()));

    acmList = ui->tableWidget;
    acmList->setSelectionBehavior(QAbstractItemView::SelectRows);
    acmList->setSelectionMode(QAbstractItemView::SingleSelection);

    mediator = med;

    candidateSet = mediator->launchACM();

    updateListView();
}

void ACMListView::handleButtonClose()
{
    close();
}
void ACMListView::handleButtonDetail()
{
    QModelIndex currentIndex = acmList->currentIndex();
    int i = acmList->item(currentIndex.row(), acmList->columnCount()-1)->text().toInt();
    ACMDetailDialog diag(mediator, currentID, candidateSet->get(i), this);
    diag.setWindowTitle(QString::fromStdString(candidateSet->get(i)->getClient()->getName() + " x " + candidateSet->get(i)->getAnimal()->getName()));
    diag.exec();
}

//Update the ListView, inserts all values
void ACMListView::updateListView()
{
    acmList->setRowCount(mediator->getNumEntities('a'));

    QStringList columnNames = {"Pet", "Client", "Compatability", "Match ID"};
    acmList->setColumnCount(columnNames.length());
    acmList->setHorizontalHeaderLabels(columnNames);

    for (int i = 0; i < candidateSet->getSize(); i++)
    {
        //Create item widgets for row
	QTableWidgetItem *pet = new QTableWidgetItem (QString::fromStdString (candidateSet->get(i)->getAnimal()->getName()));
	QTableWidgetItem *client = new QTableWidgetItem (QString::fromStdString (candidateSet->get(i)->getClient()->getName()));
	QTableWidgetItem *compatability = new QTableWidgetItem (QString::number (candidateSet->get(i)->getCompatibility()));
	QTableWidgetItem *j = new QTableWidgetItem (QString::number (i));

        //set all as un-editable
	pet->setFlags(pet->flags() ^ Qt::ItemIsEditable);
	client->setFlags(client->flags() ^ Qt::ItemIsEditable);
	compatability->setFlags(compatability->flags() ^ Qt::ItemIsEditable);
	j->setFlags(j->flags() ^ Qt::ItemIsEditable);

        //place items into list view
	acmList->setItem(i, 0, pet);    //Pet
	acmList->setItem(i, 1, client);    //Client
	acmList->setItem(i, 2, compatability);    //Compatability
	acmList->setItem(i, 3, j);    //Compatability
    }

    acmList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    acmList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //sort ascending
    acmList->sortByColumn(acmList->columnCount()-1, Qt::SortOrder::DescendingOrder);
}

//destructor
ACMListView::~ACMListView()
{
    delete ui;
}
