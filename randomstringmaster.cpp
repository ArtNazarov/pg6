#include "randomstringmaster.h"
#include <QChar>
#include <QString>
#include <QRandomGenerator>
RandomStringMaster::RandomStringMaster()
{

}

QString RandomStringMaster::rand_str(int n){
    QRandomGenerator *rg = QRandomGenerator::global();
    QString res;
    int code;
    res = "";
    for (int i=0;i<n;i++){
        code = rg->bounded(33, 122-33);
        res += QChar(code);
    };
    return res;
}
