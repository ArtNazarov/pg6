#include "modellist.h"
#include "modelrecord.h"
#include <QList>

ModelList::ModelList()
{
    this->items = new QList<ModelRecord>();
}

ModelList::~ModelList()
{
    delete this->items;
}


void ModelList::addItem(ModelRecord* item){
    item->index = this->items->count()+1;
    this->items->append( *item  );
}
