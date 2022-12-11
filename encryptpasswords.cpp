#include "encryptpasswords.h"
#include <QByteArray>
#include <QTextCodec>
#include <QDebug>


EncryptPasswords::EncryptPasswords()
{
 qDebug() << "test";
}

void debug_arr(QByteArray arr){

    for (int i=0;i<arr.size();i++){
        qDebug() << arr[i] << " | ";
    };

    qDebug() << "\n\r";

}

QString EncryptPasswords::crypt_enc(QString inputStr, QString pasw){



    QString res = "";

    int k = 0;

    QTextCodec* defaultTextCodec = QTextCodec::codecForName("UTF-8");

    QByteArray input_bytes = defaultTextCodec->fromUnicode(inputStr);
    QByteArray pasw_bytes = defaultTextCodec->fromUnicode(pasw);
    QByteArray out_bytes = QByteArray(input_bytes.size(), 0);
    debug_arr(input_bytes);
    debug_arr(pasw_bytes);
    debug_arr(out_bytes);



    for (int i=0;i<input_bytes.size();i++){

       char chr1 = input_bytes[i];
       char chr2 = pasw_bytes[k];


       if (chr2 > 90){
            out_bytes[i] = chr1 + 1;
       }
       else
       {
           out_bytes[i] = chr1 - 1 ;
       };

        k++;

        if (k>=pasw.count()) k = 0;
    }

    debug_arr(out_bytes);

    res = QString::fromUtf8(out_bytes);

    return res;
}

QString EncryptPasswords::crypt_dec(QString inputStr, QString pasw){
    QString res = "";

    int k = 0;

    QTextCodec* defaultTextCodec = QTextCodec::codecForName("UTF-8");

    QByteArray input_bytes = defaultTextCodec->fromUnicode(inputStr);
    QByteArray pasw_bytes = defaultTextCodec->fromUnicode(pasw);
    QByteArray out_bytes = QByteArray(input_bytes.size(), 0);
    debug_arr(input_bytes);
    debug_arr(pasw_bytes);
    debug_arr(out_bytes);


    for (int i=0;i<input_bytes.size();i++){

       char chr1 = input_bytes[i];
       char chr2 = pasw_bytes[k];

       if (chr2 > 90){
            out_bytes[i] = chr1 - 1;
       }
       else
       {
           out_bytes[i] = chr1 + 1;
       };

        k++;

        if (k>=pasw.count()) k = 0;
    }

    debug_arr(out_bytes);

    res = QString::fromUtf8(out_bytes);

    return res;
}

