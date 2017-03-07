#include "contenitore.h"

//NODO
contenitore::nodo::nodo():rif(0){}

contenitore::nodo::nodo(utente* u,const smartP& sp):user(u),next(sp),rif(0){}

QString contenitore::nodo::getUser()const{return user->getUsUname();}

utente* contenitore::nodo::getUtente()const{return user;}

//CONTENITORE
contenitore::contenitore(const contenitore& c):primo(c.primo){}

bool contenitore::vuoto()const{return !primo;}

void contenitore::AggUtente(utente *u){primo=new nodo(u,primo);}

void contenitore::RimUtente(utente *u){
    smartP user1=primo, utentePrec, user2;
    smartP vPrimo=primo;
    primo=0;

    while (user1!=0 && !(user1->user!=u)) {
        user2=new nodo(user1->user,user1->next);

        if(utentePrec==0)
            primo=user2;
        else
            utentePrec->next=user2;
        utentePrec=user2;
        user1=user2->next;
    }
    if(user1==0)
        primo=vPrimo;
    else if(utentePrec==0)
        primo=user1->next;
    else
        utentePrec->next=user1->next;
}

utente* contenitore::getUtente(){
    utente tmp=primo->user;
    primo=primo->next;
    return tmp;
}

contenitore& contenitore::operator =(const contenitore& cn){
    if(this!=&cn){
        primo=cn.primo;
        if(primo->rif!=0)
            primo->rif++;
    }
    return *this;
}

utente* contenitore::iteratore::getUtentiIT()const{
    return punt.getSmartUser();
}

contenitore::iteratore contenitore::begin()const{
    iteratore tmp;
    tmp.punt=primo;
    return tmp;
}

contenitore::iteratore contenitore::end()const{
    iteratore tmp;
    tmp.punt=0;
    return tmp;
}

utente* contenitore::operator [](const iteratore &it)const{
    return (it.punt)->user;
}

bool contenitore::iteratore::operator ==(iteratore it) const{
    return punt==it.punt;
}

bool contenitore::iteratore::operator !=(iteratore it) const{
    return punt!=it.punt;
}

QString contenitore::iteratore::utentiIT()const{
    return punt.smartUser();
}

contenitore::iteratore& contenitore::iteratore::operator++(){
    if(punt!=0) punt=punt->next;
    return *this;
}

contenitore::iteratore contenitore::iteratore::operator++(int){
    iteratore tmp=*this;
    if(punt!=0) punt=punt->next;
    return tmp;
}

utente* contenitore::iteratore::operator*()const{
    return punt->user;
}

contenitore::smartP::smartP(nodo* n):punt(n){
    if(punt) punt->rif++;
}

contenitore::smartP::smartP(const smartP &sm):punt(sm.punt){
    if(punt)punt->rif++;
}

contenitore::smartP::~smartP(){
    if(punt!=0){
        punt->rif--;
        if(punt->rif==0)
            delete punt;
    }
}

contenitore::smartP::operator=(const smartP& sm){
    if(*this!=&sm){
        nodo* tmp=punt;
        punt=sm.punt;
        if(punt)
            punt->rif++;
        if(tmp){
            tmp->rif--;
            if(!tmp->rif)
                delete tmp;
        }
    }
    return *this;
}

contenitore::nodo& contenitore::smartP::operator*()const{
    return* punt;
}

contenitore::nodo* contenitore::smartP::operator ->()const{
    return punt;
}

QString contenitore::smartP::smartUser()const{
    return punt->getUser();
}

utente* contenitore::smartP::getSmartUser()const{
    return punt->getUtente();
}

bool contenitore::smartP::operator==(const smartP& sm)const{
    return punt==sm.punt;
}

bool contenitore::smartP::operator !=(const smartP& sm)const{
    return punt!=sm.punt;
}
