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
//    QModelIndex currentIndex = clientList->currentIndex();
//    std::string name = clientList->item(currentIndex.row(), 0)->text().toStdString();
//    ClientDetailDiag diag(manager, manager->getClientWithName(name), this);
//    diag.exec();
}

//Update the ListView, inserts all values
void ClientListView::updateListView()
{
    //std::cout<< manager->getNumClients() << std::endl;
    clientList->setRowCount(manager->getNumClients());

    QStringList columnNames = {"Name", "ID"};
    clientList->setColumnCount(columnNames.length());
    clientList->setHorizontalHeaderLabels(columnNames);

    Client *a = manager->getClientCollection();

    for(int i = 0; i < manager->getNumClients(); i++)
    {
        //Create item widgets for row
        QTableWidgetItem *name = new QTableWidgetItem (QString::fromStdString(a[i].getName()));\
        QTableWidgetItem *id = new QTableWidgetItem (QString::number(a[i].getID()));

        //set all as un-editable
        name->setFlags(name->flags() ^ Qt::ItemIsEditable);
        id->setFlags(id->flags() ^ Qt::ItemIsEditable);

        //place items into list view
        clientList->setItem(i, 0, name);    //Name
        clientList->setItem(i, 1, id);    //ID
    }
    //set dimensions
    clientList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    clientList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    clientList->setColumnWidth(0, 140); //Name
    clientList->setColumnWidth(1, 140); //ID
    //sort ascending
    clientList->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

//destructor
ClientListView::~ClientListView()
{
    delete ui;
}
