#ifndef PASSSPLITER_H
#define PASSSPLITER_H
#include <QtGui/QtGui>
#include <stdio.h>


class PassSpliter
{
public:
    PassSpliter(QString dirtolist ="rawdata",QString desdir="passdata");
    void openFile(QString filename);
    void closeFile();
    void setFilename(QString str);
    QStringList listallfile();

    virtual void splitFile();
    virtual void saveFile(QStringList password);
protected:
    QFile file;
    QString filename;
    QString dirtolist;
    QString desdir;
};

#endif // PASSSPLITER_H
