#ifndef UTENTE_H
#define UTENTE_H
#include<QString>
#include<QDate>
#include<list>
#include<QXmlStreamWriter>


class datiCarta
{
private:
    QString numCarta;
    QString cvc;
    QString intestatario;
public:
    datiCarta(QString n, QString c,QString i):numCarta(n),cvc(c),intestatario(i){}
    static datiCarta* getDati(QXmlStreamReader&); //Lettura da database

    QString getNumCarta()const;
    QString getCvc()const;
    QString getIntest()const;

    void setNumC(const QString& n);
    void setCvc(const QString& c);
    void setIntest(const QString& i);
};

class username{
private:
    const QString uname;
public:
    username(QString a):uname(a){}
    const QString& getUser()const{return uname;}
};

class utente{
 private:
    QString nome;
    QString cognome;
    QString indirizzo;
    QString password;
    QDate dataNascita;
    datiCarta* cartaDiCredito;
    username usUname;
    list<articolo>Acquistati;
public:
    utente(QString n,QString c,QString i,QString psw, QString d,datiCarta* cc,username u,list<articolo>acq);
    void modificaInfo(const QString& n,const QString& c, const QString& i,const QString& pw, const QDate& dn,
                      const QString& nc,const QString& cv,const QString& Inte);

    QString getNome()const;
    QString getCognome()const;
    QString getIndirizzo()const;
    QString getPassword()const;
    QDate getDataNascita()const;
    QString getStrData()const;
    QString getNumCarta()const;
    QString getCvc()const;
    QString getIntest()const;
    QString getUsUname()const;

    virtual QString classeUtente()const=0;
    virtual QString stampaClasseUtente()const=0;
    virtual void regClasse(QXmlStreamWriter& xmlWriter)const=0;
    virtual bool ricercaArticolo(const articolo* art,const QString& ricerca)const=0;

};

#endif // UTENTE_H
