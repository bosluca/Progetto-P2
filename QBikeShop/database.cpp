#include "database.h"
//QString utentidatabase::fileutenti = "../Progetto/utentiDb.xml";
//QString articolidatabase::filearticoli = "../Progetto/articoliDb.xml";

utentidatabase::utentidatabase(){
    Load();
}

utentidatabase::~utentidatabase(){
    Close();
    contenitore::iteratore it=usDB.begin();
    for(;it!=usDB.end();++it){
        QString tmp=it.getUtentiIT()->getUsUname();
        rimuoviUtente(tmp);
    }
}

void utentidatabase::togli(const QString &uname){
    contenitore::iteratore it=usDB.begin();
    for(;it!=usDB.end();++it){
        if(it.getUtentiIT()->getUsUname()==uname)
            usDB.RimUtente(*it);
    }
}

void utentidatabase::rimuoviUtente(const QString &uname){
    togli(uname);
}

contenitore::iteratore utentidatabase::begin(){return usDB.begin();}
contenitore::iteratore utentidatabase::end(){return usDB.end();}

void utentidatabase::Load(){
    QString username="provv";
    username* u=0;
    QString classe="base";
    QString n=0; //nome
    QString c=0; //cognome
    QString i=0; //indirizzo
    QString pw=0; //password
    QString dataNascita=0;
    datiCarta* dc=0;
    //QString t;
    bool prem=false;

    QString idArt=0;
    QString nA=0; //nome articolo
    int prz=0;
    list<articolo*> acq;

    QFile qfile(fileUser);
    qfile.open(QFile::ReadWrite);
    qfile.close();

    if(!qfile.open(QFile::ReadOnly | QFile::Text))
        std::cout<<" Errore con i file " << std::endl;

    QXmlStreamReader xmlReader(&qfile);
}


