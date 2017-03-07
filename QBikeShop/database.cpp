#include "database.h"

QString utentiDatabase::fileUser=""; //path
QString articoliDatabase::fileArt="";//path

utentiDatabase::utentiDatabase(){Load();}

utentiDatabase::~utentiDatabase(){
    Close();
    contenitore::iteratore it=userDB.begin();
    for(;it!=userDB.end();it++){
        QString el=it.getUtentiIT()->getUsUname();
        remUtente(el);
    }
}

void utentiDatabase::rimuovi(const QString &usr){
    contenitore::iteratore it=userDB.begin();
    for(;it!=userDB.end();++it){
        if(it.getUtentiIT()->getUsUname()==usr)
            userDB.RimUtente(*it);
    }
}

void utentiDatabase::remUtente(const QString &uname){
    rimuovi(uname);
}

contenitore::iteratore utentiDatabase::begin(){return userDB.begin();}
contenitore::iteratore utentiDatabase::end(){return userDB.end();}


std::list<QString> articoliDatabase::leggiAcquistati(QXmlStreamReader &xmlReader){
    std::list<QString>ris;
    while(!xmlReader.isEndElement()|| !(xmlReader.name()=="acquistati")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name=="acquisto")
                ris.push_back(xmlReader.readElementText());
        }
        xmlReader.readNext();
    }
    return ris;
}

void utentiDatabase::Load(){
    QString Username="momentaneo";
    username* u=0;
    QString classeU="base";
    QString n=0; //nome
    QString c=0; //cognome
    QString i=0; //indirizzo
    QString psw=0; //password
    QString dataN=0; //data di nascita
    datiCarta* dc=0;
    bool prem=false; //premium
    QString idAr=0;
    QString na=0; //nome articolo
    int prz=0; //prezzo
    std::list<articolo>acq=std::list<articolo>();
    QFile qfile(fileUser);
    qfile.open(QFile::ReadWrite);
    qfile.close();
    if(!qfile.open(QFile::ReadOnly | QFile::Text))
        std::cout << "Errore durante l'apertura del file!!" << std::endl;

    QXmlStreamReader xmlReader(&qfile);
    xmlReader.readNext();

    while(!xmlReader.atEnd()){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="utentiDatabase"){
                xmlReader.readNext();
            }
        }
    }

}
