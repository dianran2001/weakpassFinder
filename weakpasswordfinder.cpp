#include "weakpasswordfinder.h"

WeakPasswordFinder::WeakPasswordFinder(QString dirtolist ,QString desdir)
    :PassSpliter(dirtolist,desdir)
{
    //qDebug() << dirtolist;
}

void WeakPasswordFinder::passwordCounter(){
    creatPasswordList();
    sortPasswordList();

    qDebug() << "Finding weakpass...";
    QString eachpassword;
    QString oldpass("95847415&*^#*/*");
    foreach(eachpassword,passwordlist){
        //qDebug()<<eachpassword;
        if(eachpassword != oldpass){
            WEAK temp={eachpassword,1};
            weakpasslist.append(temp);
        }else{
            weakpasslist.back().count++;
        }
        oldpass = eachpassword;
    }

    qDebug()<<"sort result ...";
    sortWeakpassList();
    /**
    //test  
    foreach(WEAK weak,weakpasslist){
        qDebug()<<weak.password << weak.count;
    }
    //
    **/
    qDebug()<<"saving result ...";
    saveWeakPassword(20);
}

void WeakPasswordFinder::creatPasswordList(){
    QString line;
    QStringList filelist;
    QString temp;
    //passwordlist.clear();

    qDebug()<<"Reading password file...";

    filelist = listallfile();

    foreach(temp,filelist){
        setFilename(temp);
        openFile(dirtolist+"/"+filename);
        QTextStream stream(&file);
        while(!stream.atEnd()){
            line = stream.readLine();
            passwordlist << line;
        }
        closeFile();
    }
}

void WeakPasswordFinder::sortPasswordList(){
    //qSort(passwordlist.begin(),passwordlist.end(),caseInsensitiveLessThan);
    passwordlist.sort();
    //qDebug()<<passwordlist;
}

void WeakPasswordFinder::sortWeakpassList(){
    //weakpasslist.sort(caseInsensitiveLessThan);
    qSort(weakpasslist.begin(),weakpasslist.end(),caseInsensitiveLessThan);
}

void WeakPasswordFinder::saveWeakPassword(unsigned long int mincount){
    WEAK eachweak;
    openFile(desdir+"/"+"weakpasswordcount.txt");
    QTextStream stream(&file);
    foreach(eachweak,weakpasslist){
        //qDebug() << eachweak.count;
        if(eachweak.count < mincount){
            break;
        }else{
            stream << eachweak.password<<"\t"<<eachweak.count<<"\n";
        }
    }
    closeFile();

    //save file with no count number
    openFile(desdir+"/"+"weakpasswordlist.txt");
    foreach(eachweak,weakpasslist){
        //qDebug() << eachweak.count;
        if(eachweak.count < mincount){
            break;
        }else{
            stream << eachweak.password<<"\n";
        }
    }
    closeFile();
}










