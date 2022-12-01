#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataloader.h"
#include "datasaver.h"
#include "modellist.h"
#include "modelrecord.h"
#include <QTableView>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    list = new ModelList();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete list;
    delete ui;
}

void MainWindow::saveData(){

 DataSaver* dw = new DataSaver();
 dw->doSave(this->list);
 delete dw;

}
void MainWindow::loadData(){

    DataLoader* dl = new DataLoader();
    dl->doLoad(this->list);
    delete dl;
}

void MainWindow::modelToWidget(){


     QStringList* modelListView = new QStringList();
     QStringListModel* model = new QStringListModel(this);

     for (int i=0;i<this->list->items->count();i++){
        *modelListView << list->items->at(i).url;
     }

        model->setStringList(*modelListView);


        ui->listView->setModel(model);

};









void MainWindow::on_btnAddData_clicked()
{
  ModelRecord* item = new ModelRecord();

  item->login = ui->leLogin->text();
  item->password = ui->lePassword->text();
  item->url = ui->leUrl->text();
  item->note = ui->leNote->text();


  this->list->addItem(item);
  modelToWidget();
}


void MainWindow::on_btnSaveData_clicked()
{
     saveData();
}


void MainWindow::on_btnLoadFromFile_clicked()
{
    loadData();
    modelToWidget();
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    int z = index.row();
    ui->leLogin->setText( this->list->items->at(z).login  );
    ui->lePassword->setText( this->list->items->at(z).password  );
    ui->leUrl->setText( this->list->items->at(z).url  );
    ui->leNote->setText( this->list->items->at(z).note  );
    this->current_item = z;
    ui->lbItemIndex->setText(QString(QString::number(z)));

}


void MainWindow::on_btnApplyChanges_clicked()
{

    int z = this->current_item;

    ModelRecord* myItem = new ModelRecord();

    myItem->setValues(
                ui->leLogin->text(),
                ui->lePassword->text(),
                ui->leUrl->text(),
                ui->leNote->text()
                );

    this->list->items->replace(z, *myItem);

    modelToWidget();

}

