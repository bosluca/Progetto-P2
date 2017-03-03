#include "utente.h"

utente::utente(QString n,QString c, QString i,QString psw,QDate d, datiCarta* cc,username u,list<articolo>acq){
    nome=n;
    cognome=c;
    indirizzo=i;
    password=QString(QCryptographicHash::hash((psw),QCryptographicHash::Md5).toHex()); //password criptata e salvata come QString
    dataNascita=d;
    cartaDiCredito=cc;
    usUname=u;
    Acquistati=acq;
}

QString datiCarta::getNumCarta()const{return numCarta;}
QString datiCarta::getCvc()const{return cvc;}
QString datiCarta::getIntest()const{return intestatario;}

//lettura da database dei dati della carta da implementrare
datiCarta* datiCarta::getDati(QXmlStreamReader &){
        //da fare
}

void datiCarta::setNumC(const QString& n){
    numCarta=n;
}
void datiCarta::setCvc(const QString& c){
    cvc=c;
}
void datiCarta::setIntest(const QString &i){
    intestatario=i;
}

QString utente::getNome()const{return nome;}
QString utente::getCognome()const{return cognome;}
QString utente::getIndirizzo()const{return indirizzo;}
QString utente::getPassword()const{return password;}
QDate utente::getDataNascita()const{return dataNascita;}
QString utente::getStrData()const{return dataNascita.toString("dd.MM.yyyy");}
QString utente::getNumCarta()const{return cartaDiCredito->getNumCarta();}
QString utente::getCvc()const{return cartaDiCredito->getCvc();}
QString utente::getIntest()const{return cartaDiCredito->getIntest();}
QString utente::getUsUname()const{return usUname.getUser();}
list<articolo> utente::getAcquistati()const{return Acquistati;}

