#include "datasaver.h"
#include "modellist.h"
#include <QFile>
#include <QTextStream>
#include "encryptpasswords.h"


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
