#ifndef DATASAVER_H
#define DATASAVER_H

#include "modellist.h"
#include <QFile>
#include <QTextStream>

class DataSaver
{
public:
    QString filename;
    DataSaver();
    void doSave(ModelList* ml);
};

#endif // DATASAVER_H
