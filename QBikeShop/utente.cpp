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
username utente::getUsername()const{return usUname;}
datiCarta* utente::getCarta() const{return cartaDiCredito;}
list<articolo*> utente::getAcquistati()const{return Acquistati;}

void utente::setNome(const QString &n){nome=n;}
void utente::setCognome(const QString &c){cognome=c;}
void utente::setIndirizzo(const QString &i){indirizzo=i;}
void utente::setPassword(const QString &pw){password=pw;}
void utente::setDataNascita(const QDate &dn){dataNascita=dn;}
void utente::setNumCarta(const QString &nc){cartaDiCredito->setNumC(nc);}
void utente::setCvc(const QString &cv){cartaDiCredito->setCvc(cv);}
void utente::setIntestatario(const QString &in){cartaDiCredito->setIntest(in);}
void utente::setAcquistati(articolo* art){
    Acquistati.push_back(art);
}

virtual utente::~utente(){delete &cartaDiCredito;}


void utente::modificaInfo(const QString &n, const QString &c, const QString &i, const QString &pw, const QDate &dn, const QString &nc,
                          const QString &cv, const QString &Inte){
    setNome(n);
    setCognome(c);
    setIndirizzo(i);
    setPassword(pw);
    setDataNascita(dn);
    cartaDiCredito->setNumC(nc);
    cartaDiCredito->setCvc(cv);
    cartaDiCredito->setIntest(Inte);
}


