#ifndef MODELRECORD_H
#define MODELRECORD_H

#include <QString>


class ModelRecord
{
public:
    int index;
    QString login;
    QString url;
    QString password;
    QString note;
    ModelRecord();
    void setValues(QString aLogin, QString aPass, QString anUrl, QString aNote);
};

#endif // MODELRECORD_H
