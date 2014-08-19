#include <QCoreApplication>
#include "passspliter.h"
#include "weakpasswordfinder.h"

int main(int argc, char *argv[])
{
    //test PassSpliter class
    //you may need to rewrite couple of function to split the original file
    /**
    QStringList filetable;
    QString filename;
    PassSpliter spliter;
    filetable = spliter.listallfile();
    //qDebug() <<filetable;

    foreach(filename, filetable){
        spliter.setFilename(filename);
        spliter.splitFile();
        qDebug() << filename+"-----done";
    }
    **/
    //////////

    //weakpassworldfinder test
    WeakPasswordFinder finder;
    //finder.setFilename("16.10WW.txt");
    finder.passwordCounter();
    return 0;
}
