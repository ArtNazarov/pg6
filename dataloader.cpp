#include "dataloader.h"
#include "modellist.h"
#include "modelrecord.h"
#include <QFile>
#include <QTextStream>
#include "encryptpasswords.h"
#include <QDebug>

#include <QSqlQuery>

DataLoader::DataLoader(){

}

void DataLoader::doLoad(ModelList* ml)
{
    QString pasw = "h7yads";
    EncryptPasswords* e = new EncryptPasswords();
    ml->items->clear();

    QFile fIn(this->filename);
    if (fIn.open(QFile::ReadOnly | QFile::Text)) {
      QTextStream sIn(&fIn);
      while (!sIn.atEnd()) {
         ModelRecord* item = new ModelRecord();

         item->login =  e->xoring_dec(  sIn.readLine() , pasw);
         item->password = e->xoring_dec( sIn.readLine(), pasw);
         item->url = e->xoring_dec( sIn.readLine(), pasw);
         item->note = e->xoring_dec(  sIn.readLine() , pasw);

        ml->addItem( item  );

      };
      fIn.close();
    };
    delete e;
}

void DataLoader::doLoadFromSqlite(ModelList* ml){


   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(filename);
   if (!db.open())
   {
       qDebug() << "error!!!";
   }

   QSqlQuery query(db);

    QString pasw = "h7yads";
    EncryptPasswords* e = new EncryptPasswords();
    ml->items->clear();




    query.exec("SELECT * FROM passwords");

    while (query.next())
    {
       QString login = query.value("login").toString();
       QString password = query.value("password").toString();
       QString url = query.value("url").toString();
       QString note = query.value("note").toString();


       ModelRecord* item = new ModelRecord();

       item->login =  e->xoring_dec(  login , pasw);
       item->password = e->xoring_dec( password, pasw);
       item->url = e->xoring_dec( url, pasw);
       item->note = e->xoring_dec(  note , pasw);

       ml->addItem( item  );


    }
}
