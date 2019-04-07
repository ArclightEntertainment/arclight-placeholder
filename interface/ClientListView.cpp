#include "ClientListView.h"
#include "ui_listview.h"
#include <iostream>

//Constructor, requires QWidget and an ClientManager
ClientListView::ClientListView(CUACSController *med, int cID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    detailsButton = ui->detailsButton;

    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(detailsButton, SIGNAL(released()), this,SLOT(handleButtonDetail()));

    clientList = ui->tableWidget;
    clientList->setSelectionBehavior(QAbstractItemView::SelectRows);
    clientList->setSelectionMode(QAbstractItemView::SingleSelection);

    mediator = med;
    currentID = cID;

    updateListView();
}

void ClientListView::handleButtonClose()
{
    close();
}
void ClientListView::handleButtonDetail()
{
    QModelIndex currentIndex = clientList->currentIndex();
    int id = clientList->item(currentIndex.row(), clientList->columnCount()-1)->text().toInt();

    ClientDetailDiag diag(mediator, currentID, mediator->getClientWithId(id), false, this);
    diag.setWindowTitle(QString::fromStdString(mediator->getClientWithId(id)->getName() + "'s Profile"));
    diag.exec();
    updateListView();
}

//Update the ListView, inserts all values
void ClientListView::updateListView()
{
    clientList->setRowCount(mediator->getNumEntities('c'));

    QStringList columnNames = {"Title", "First Name", "Last Name", "ID"};
    clientList->setColumnCount(columnNames.length());
    clientList->setHorizontalHeaderLabels(columnNames);

    Iterator<UClient*> *a = mediator->createClientIterator();
    int i = 0;
    while(!a->isDone())
    {
        //Create item widgets for row
	QTableWidgetItem *title = new QTableWidgetItem (QString::fromStdString(a->currentItem()->getString(static_cast<int>(ClientAttribute::PREF_TITLE))));
	QTableWidgetItem *lname = new QTableWidgetItem (QString::fromStdString(a->currentItem()->getString(static_cast<int>(ClientAttribute::LAST_NAME))));
        QTableWidgetItem *fname = new QTableWidgetItem (QString::fromStdString(a->currentItem()->getName()));
        QTableWidgetItem *id = new QTableWidgetItem (QString::number(a->currentItem()->getID()));

        //set all as un-editable
        title->setFlags(title->flags() ^ Qt::ItemIsEditable);
        fname->setFlags(fname->flags() ^ Qt::ItemIsEditable);
        lname->setFlags(lname->flags() ^ Qt::ItemIsEditable);
        id->setFlags(id->flags() ^ Qt::ItemIsEditable);

        //place items into list view
        clientList->setItem(i, 0, title);    //Title
        clientList->setItem(i, 1, fname);    //FName
        clientList->setItem(i, 2, lname);    //LName
        clientList->setItem(i, 3, id);    //ID

        i++;
        a->next();
    }
    //set dimensions
    clientList->setColumnWidth(0, 40); //Title
    clientList->setColumnWidth(1, 200); //FName
    clientList->setColumnWidth(2, 200); //LName
    clientList->setColumnWidth(3, 60); //ID

    clientList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    clientList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //sort ascending
    clientList->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

//destructor
ClientListView::~ClientListView()
{
    delete ui;
}
