#ifndef DATALOADER_H
#define DATALOADER_H

#include "modellist.h"
#include <QFile>
#include <QTextStream>

class DataLoader
{
public:
    QString filename;
    DataLoader();
    void doLoad(ModelList* ml);
    void doLoadFromSqlite(ModelList *ml);
};

#endif // DATALOADER_H
