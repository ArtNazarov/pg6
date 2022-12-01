#ifndef RANDOMSTRINGMASTER_H
#define RANDOMSTRINGMASTER_H

#include <QChar>
#include <QString>


class RandomStringMaster
{
public:
    RandomStringMaster();
    static QString rand_str(int n);
};

#endif // RANDOMSTRINGMASTER_H
