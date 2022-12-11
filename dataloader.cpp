#include "dataloader.h"
#include "modellist.h"
#include "modelrecord.h"
#include <QFile>
#include <QTextStream>
#include "encryptpasswords.h"

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
