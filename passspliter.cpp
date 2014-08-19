#include "passspliter.h"

PassSpliter::PassSpliter(QString dirtolist,QString desdir)
{
    this->dirtolist =dirtolist ;
    this->desdir = desdir;
}

void PassSpliter::openFile(QString filename){
    file.setFileName(filename);
    if(!file.open(QIODevice::ReadWrite)){
        qDebug() << "open file: " + filename + " error!";
        return;
    }

}

void PassSpliter::closeFile(){
    file.close();
}

void PassSpliter::saveFile(QStringList password){
    QString line;
    openFile(desdir+"/"+filename);
    QTextStream stream(&file);
    foreach(line,password){
        stream << line+"\n";
        //qDebug()<<line;
    }
    closeFile();
}

QStringList PassSpliter::listallfile(){
    QDir dir(dirtolist);
    return dir.entryList(QDir::Files);
}

void PassSpliter::setFilename(QString str){
    filename = str;
}

void PassSpliter::splitFile(){
    QString string;
    QStringList password;
    QRegExp reg("----(.+)");
    reg.setMinimal(true);

    openFile(dirtolist+"/"+filename);
    QTextStream stream(&file);
    while(!stream.atEnd()){
        string = stream.readLine();
        if(string.isEmpty()){continue;}
        //qDebug() << string;
        password << string.split(reg,QString::SkipEmptyParts)[1];
    }
    //qDebug() << password;
    closeFile();
    saveFile(password);
}

