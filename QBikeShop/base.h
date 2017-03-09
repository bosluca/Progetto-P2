#ifndef BASE_H
#define BASE_H
#include<utente.h>

class base:public utente{
public:
    base(QString n,QString c,QString i,QString psw, QDate d,datiCarta* cc,username u,list<articolo>acq):utente(n,c,i,psw,d,cc,u,acq){}
    virtual QString classeUtente()const;
    virtual QString stampaClasseUtente()const;
    virtual void regClasse(QXmlStreamWriter& xmlWriter)const;
    virtual bool ricercaArticolo(const articolo* art,const QString& ricerca)const;
    void upgradeToPrem(utente* us);
};

#endif // BASE_H
