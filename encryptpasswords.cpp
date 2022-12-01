#include "encryptpasswords.h"

EncryptPasswords::EncryptPasswords()
{

}

QString EncryptPasswords::xoring_enc(QString inputStr, QString pasw){
    QString res = "";

    int k = 0;
    for (int i=0;i<inputStr.count();i++){

        int chr1 = inputStr.at(i).toLatin1();
        int chr2 = pasw.at(k).toLatin1();


        res = res + QChar(32+ (chr1 ^ chr2));

        k++;

        if (k>=pasw.count()) k = 0;
    }

    return res;
}

QString EncryptPasswords::xoring_dec(QString inputStr, QString pasw){
    QString res = "";

    int k = 0;
    for (int i=0;i<inputStr.count();i++){

        int chr1 = inputStr.at(i).toLatin1()-32;
        int chr2 = pasw.at(k).toLatin1();


        res = res + QChar(chr1 ^ chr2);

        k++;

        if (k>=pasw.count()) k = 0;
    }

    return res;
}

