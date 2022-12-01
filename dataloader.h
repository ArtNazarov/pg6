#ifndef DATALOADER_H
#define DATALOADER_H

#include "modellist.h"
#include <QFile>
#include <QTextStream>

class DataLoader
{
public:
    DataLoader();
    void doLoad(ModelList* ml);
};

#endif // DATALOADER_H
