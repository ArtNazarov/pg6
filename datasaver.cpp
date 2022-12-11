#include "datasaver.h"
#include "modellist.h"
#include <QFile>
#include <QTextStream>
#include "encryptpasswords.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


DataSaver::DataSaver(){

}

void DataSaver::doSave(ModelList* ml)
{
    QString pasw = "h7yads";
    EncryptPasswords* e = new EncryptPasswords();
     QFile fOut(filename);
     if (fOut.open(QFile::WriteOnly | QFile::Text)) {
       QTextStream s(&fOut);
       for (int i = 0; i < ml->items->count(); i++){

            s << e->xoring_enc( ml->items->at(i).login, pasw) << '\n';
            s << e->xoring_enc( ml->items->at(i).password, pasw) << '\n';
            s << e->xoring_enc( ml->items->at(i).url, pasw) << '\n';
            s << e->xoring_enc( ml->items->at(i).note, pasw) << '\n';

         };
     fOut.close();
     };
     delete e;
}

void DataSaver::doSaveInSqlite(ModelList* ml){


   if (!QFile::exists(filename)){
       initSqlite();
   }

   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(filename);
   db.open();

   QString pasw = "h7yads";
   EncryptPasswords* e = new EncryptPasswords();

   QString clear_sql =  "DELETE FROM passwords WHERE 1=1";

   QSqlQuery query_clear(db);

   query_clear.exec(clear_sql);

   QString login;
   QString password;
   QString url;
   QString note;
   QSqlQuery query(db);



       for (int i = 0; i < ml->items->count(); i++){


            login = e->xoring_enc( ml->items->at(i).login, pasw) ;
            password = e->xoring_enc( ml->items->at(i).password, pasw);
            url = e->xoring_enc( ml->items->at(i).url, pasw);
            note = e->xoring_enc( ml->items->at(i).note, pasw);


            QString req =  "INSERT INTO passwords (id, login, password, url, note ) VALUES (:Id, :Login, :Password, :Url, :Note)";


            query.prepare( req );
            query.bindValue(":Id",     i);
            query.bindValue(":Login", login);
            query.bindValue(":Password",  password);
            query.bindValue(":Url", url);
            query.bindValue(":Note", note);
            query.exec();
         };
   db.close();
   delete e;
}

void DataSaver::initSqlite()
{
    QString path = filename;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    QSqlQuery query;
    query.exec(
              "create table passwords "
              "(id integer primary key, "
              "login varchar(20), "
              "password varchar(30), "
              "url varchar(30),"
              "note varchar(30))"
          );
    db.close();
}
