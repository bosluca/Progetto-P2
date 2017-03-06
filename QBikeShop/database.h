#ifndef DATABASE_H
#define DATABASE_H
#include"utente.h"
#include"base.h"
#include"premium.h"
#include"articolo.h"
#include<QXmlStreamReader>
#include<QXmlStreamWriter>
#include<QFile>
#include<list>
#include<QString>
#include"contenitore.h" //da fare

class utentiDatabase{
    static QString fileUser;
    contenitore<utente> userDB;
public:
    utentiDatabase();
    ~utentiDatabase();

    contenitore<utente>::iteratore begin();
    contenitore<utente>::iteratore end();

    void aggUtente(const QString& n, const QString& c,const QString& i,const QString& pw, const QDate& dn,const QString& nc,
                   const QString& cv,const QString& Inte);

    utente* findUser(const QString& uname)const;
    bool matchUtente(const QString& uname)const;
    bool empty()const;
    void remUtente(const QString& uname);
    void upgradeToPrem(const QString& usr);
    void downgradeToBase(const QString& usr);
    void rimuovi(const QString& usr);
    void modificaProfiloUtente(const QString& n, const QString& c,const QString& i,const QString& pw, const QDate& dn,const QString& nc,
                               const QString& cv,const QString& Inte);
    void Load();
    void Close();
};

class articoliDatabase{
private:
    static QString fileArt;
    std::list<articolo*> articDB;
public:
    articoliDatabase();
    ~articoliDatabase();

    std::list<articolo*>::iterator begin();
    std::list<articolo*>::iterator end();
    std::list<articolo*>::const_iterator begin()const;
    std::list<articolo*>::const_iterator end()const;

    QString getNameById(const QString&)const;

    std::list<QString> leggiAcquistati(QXmlStreamReader& xmlReader);
    std::list<articolo*> getAcqDB(){return articDB;}

    bool trovaID(const QString& id)const;
    bool isEmpty()const;
    void rimArticolo(const QString& idA);
    void insertArt(const QString& id, const QString& n,const QString& d,const double p,const int q,const bool pr);
    void acquista(const QString& idA);
    void setAcquistati(const QString& idA);

    void Load();
    void Close();

};

#endif // DATABASE_H
