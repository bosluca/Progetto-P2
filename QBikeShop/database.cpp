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
            else if(xmlReader.name()=="utente")
                xmlReader.readNext();
            else if(xmlReader.name()=="username"){
                Username=xmlReader.readElementText(); //compilo l'username
                u=new username(Username);
            }
            else if(xmlReader.name()=="classe")
                classeU=xmlReader.readElementText();
            else if(xmlReader.name()=="dati"){
                while (!xmlReader.isEndElement()||!(xmlReader.name()=="dati")){
                    if(xmlReader.isStartElement()){
                        if(xmlReader.name()=="nome")
                            n=xmlReader.readElementText();
                        else if(xmlReader.name()=="cognome")
                            c=xmlReader.readElementText();
                        else if(xmlReader.name()=="indirizzo")
                            i=xmlReader.readElementText();
                        else if(xmlReader.name()=="password")
                            psw=xmlReader.readElementText();
                        else if(xmlReader.name()=="datanascita")
                            dataN=xmlReader.readElementText();
                }
                xmlReader.readNext();
            }
        }
        else if(xmlReader.name()=="acquisti"){
                while(!xmlReader.isEndElement() || !(xmlReader.name()=="acquisti")){
                    if(xmlReader.isStartElement()){
                        if(xmlReader.name()=="idart")
                            idAr=xmlReader.readElementText();
                        else if(xmlReader.name()=="nomeart")
                            na=xmlReader.readElementText();
                        else if(xmlReader.name()=="prezzo")
                            prz=xmlReader.readElementText().toInt();
                        else if(xmlReader.name()=="premium"){
                            QString premUs=xmlReader.readElementText();
                            if(premUs=="true")
                                prem=true;
                            else if(premUs=="false")
                                prem=false;
                            articolo* tmp=new articolo(idAr,na,0,prz,0,prem);
                            acq.push_front(tmp);
                        }
                    }
                    xmlReader.readNext();
                }
            }
            else if(xmlReader.name()=="carta")
                dc=datiCarta::getDati(xmlReader);

    }else{
            QDate DataN(QDate::fromString(dataN,"dd.MM.yyyy"));
            if(xmlReader.isEndElement()&&xmlReader.name()=="utente"){
                if(classeU=="base"){
                    base* bas=new base(n,c,i,psw,dataN,dc,u,acq);
                    userDB.AggUtente(bas);
                    acq=std::list<articolo>();
                }else if(classeU=="premium"){
                    premium* pre=new premium(n,c,i,psw,dataN,dc,u,acq);
                }
                xmlReader.readNext();
            }
            else
                xmlReader.readNext();
        }
    }
    qfile.close();
}
