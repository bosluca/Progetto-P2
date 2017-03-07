#ifndef CONTENITORE_H
#define CONTENITORE_H
#include"utente.h"

class contenitore{
    friend class iteratore;
private:
    class nodo;
    class smartP{
    public:
        nodo* punt;
        smartP(nodo* p=0);
        smartP(const smartP&);
        ~smartP();
        smartP& operator =(const smartP&);
        bool operator ==(const smartP&)const;
        bool operator !=(const smartP&)const;
        nodo& operator*()const;
        nodo* operator->()const;
        QString smartUser()const;
        utente* getSmartUser()const;
    };
    class nodo{
    public:
        nodo();
        nodo(utente*,const smartP&);
        QString getUser()const;
        utente* getUtente()const;
        //username* getUsername()const;
        utente* user;
        smartP next;
        int rif;
    };
    smartP primo;
public:
    contenitore():primo(0){}
    contenitore(const contenitore&);
    contenitore& operator=(const contenitore&);
    bool vuoto()const;
    void AggUtente(utente*);
    void RimUtente(utente*);
    utente* getUtente();

    class iteratore{
        friend class contenitore;
    private:
        contenitore::smartP punt;
    public:
        bool operator ==(iteratore)const;
        bool operator !=(iteratore)const;
        QString utentiIT()const;
        iteratore& operator++();
        iteratore operator ++(int);
        utente* operator*()const;
        utente* getUtentiIT()const;
    };
    iteratore begin()const;
    iteratore end()const;
    utente* operator[](const iteratore&)const;
};

#endif // CONTENITORE_H
