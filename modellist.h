#ifndef MODELLIST_H
#define MODELLIST_H
#include "modelrecord.h"

class ModelList
{
public:
    QList<ModelRecord> *items;
    ModelList();
    ~ModelList();
    void addItem(ModelRecord* item);
};

#endif // MODELLIST_H
