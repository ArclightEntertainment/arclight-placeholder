#include "ClientListView.h"
#include "ui_listview.h"
#include <iostream>

//Constructor, requires QWidget and an ClientManager
ClientListView::ClientListView(ClientManager *aM, QWidget *parent) :
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

    manager = aM;

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
    ClientDetailDiag diag(manager, manager->getClientWithId(id), this);
    diag.exec();
}

//Update the ListView, inserts all values
void ClientListView::updateListView()
{
    //std::cout<< manager->getNumClients() << std::endl;
    clientList->setRowCount(manager->getNumClients());

    QStringList columnNames = {"Title", "First Name", "Last Name", "ID"};
    clientList->setColumnCount(columnNames.length());
    clientList->setHorizontalHeaderLabels(columnNames);

    Client *a = manager->getClientCollection();

    for(int i = 0; i < manager->getNumClients(); i++)
    {
        //Create item widgets for row
        QTableWidgetItem *title = new QTableWidgetItem (QString::fromStdString(a[i].getTitle()));
        QTableWidgetItem *fname = new QTableWidgetItem (QString::fromStdString(a[i].getFirstName()));
        QTableWidgetItem *lname = new QTableWidgetItem (QString::fromStdString(a[i].getLastName()));
        QTableWidgetItem *id = new QTableWidgetItem (QString::number(a[i].getClientID()));

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
    }
    //set dimensions
    clientList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    clientList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    clientList->setColumnWidth(0, 40); //Title
    clientList->setColumnWidth(1, 200); //FName
    clientList->setColumnWidth(2, 200); //LName
    clientList->setColumnWidth(3, 60); //ID
    //sort ascending
    clientList->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

//destructor
ClientListView::~ClientListView()
{
    delete ui;
}
