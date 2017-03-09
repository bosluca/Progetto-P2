#ifndef DATABASE_H
#define DATABASE_H
#include "utente.h"
#include "articolo.h"
#include "base.h"
#include "premium.h"
#include "contenitore.h"
#include<iostream>
#include<typeinfo>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
using std::list;

class utentidatabase{
private:
    static QString fileUser;
    contenitore usDB;
public:
    utentidatabase();
    ~utentidatabase();

    contenitore::iteratore begin();
    contenitore::iteratore end();

    void addUtente(const QString &n, const QString &c, const QString &i, const QString &pw, const QDate &dn, const QString& uname, const QString &nc,
                   const QString &cv, const QString &Inte);
    utente* trovaUtente(const QString& uname)const;
    bool trovaEsistente(const QString& uname)const;
    bool vuoto()const;
    void rimuoviUtente(const QString& uname);
    void upgrade(const QString& uname);
    void downgrade(const QString& uname);
    void togli(const QString& uname);
    void modProfilo(const QString &n, const QString &c, const QString &i, const QString &pw, const QDate &dn, const QString &nc,
                    const QString &cv, const QString &Inte);
    void Load();
    void Close();
};

class articolidatabase{
private:
    static QString fileArticoli;
    list<articolo*>articDB;
public:
    articolidatabase();
    ~articolidatabase();

    list<QString>leggiAcquistati(QXmlStreamReader& xmlReader);
    list<articolo*>getDatabaseA(){return articDB;}

    QString getNomeById(const QString& idArt); //dynamic cast
    bool trovaId(const QString& idA)const;
    bool vuoto()const;
    void togliArtiolo(const QString& idA);
    void inserisciArticolo(const QString& id,const QString& nome,const QString& desc,const QString& prezzo,const QString& qta, const bool& prem);
    void acquista(const QString& idA);
    void setAcq(const QString& idA);
    void Load();
    void Close();
};

#endif // DATABASE_H
