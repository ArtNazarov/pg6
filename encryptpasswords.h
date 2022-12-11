#ifndef ENCRYPTPASSWORDS_H
#define ENCRYPTPASSWORDS_H

#include <QString>

class EncryptPasswords
{
public:
    EncryptPasswords();
    QString crypt_enc(QString inputStr, QString pasw);
    QString crypt_dec(QString inputStr, QString pasw);

};

#endif // ENCRYPTPASSWORDS_H
