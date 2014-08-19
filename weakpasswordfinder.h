#ifndef WEAKPASSWORDFINDER_H
#define WEAKPASSWORDFINDER_H
#include <QtGui/QtGui>
#include <stdio.h>
#include "passspliter.h"
#include <QtAlgorithms>

typedef struct{
    QString password;
    unsigned long int count;
}WEAK;

class WeakPasswordFinder:public PassSpliter
{
public:
    WeakPasswordFinder(QString dirtolist ="passdata",QString desdir="weakdata");
    static bool caseInsensitiveLessThan(const WEAK &w1, const WEAK &w2){return w1.count > w2.count;}

    void passwordCounter();
    void creatPasswordList();
    void sortWeakpassList();
    void sortPasswordList();
    void saveWeakPassword(unsigned long int mincount);

    //void splitFile();//relaod splitfile()
private:
    QList <WEAK> weakpasslist;
    QStringList passwordlist;
};

#endif // WEAKPASSWORDFINDER_H
