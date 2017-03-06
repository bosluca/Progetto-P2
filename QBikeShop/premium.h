#ifndef PREMIUM_H
#define PREMIUM_H
#include "utente.h"
class premium:public utente{
public:
    premium(QString n,QString c,QString i,QString psw, QDate d,datiCarta* cc,username u,std::list<articolo>acq):utente(n,c,i,psw,d,cc,u,acq){}
    virtual QString classeUtente()const;
    virtual QString stampaClasseUtente()const;
    virtual void regClasse(QXmlStreamWriter& xmlWriter)const;
    virtual bool ricercaArticolo(const articolo* art,const QString& ricerca)const;
};

#endif // PREMIUM_H
