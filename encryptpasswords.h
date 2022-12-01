#ifndef ENCRYPTPASSWORDS_H
#define ENCRYPTPASSWORDS_H

#include <QString>

class EncryptPasswords
{
public:
    EncryptPasswords();
    QString xoring_enc(QString inputStr, QString pasw);
    QString xoring_dec(QString inputStr, QString pasw);

};

#endif // ENCRYPTPASSWORDS_H
