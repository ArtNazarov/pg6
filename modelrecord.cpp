#include "modelrecord.h"

ModelRecord::ModelRecord()
{
    this->index = 0;
    this->login = "";
    this->url = "";
    this->note = "";
    this->password = "";
}

void ModelRecord::setValues(QString aLogin, QString aPass, QString anUrl, QString aNote){
    this->login = aLogin;
    this->password = aPass;
    this->url = anUrl;
    this->note = aNote;

}

