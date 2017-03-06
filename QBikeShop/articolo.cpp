#include "articolo.h"

articolo::articolo(const QString &id, const QString &n, const QString &d, const double p, const int q, const bool pr):
    idArt(id),nomeArt(n),descrizione(d),prezzo(p),quantita(q),premium(p){}

QString articolo::getId()const{return idArt;}
QString articolo::getNomeA()const{return nomeArt;}
QString articolo::getDesc()const{return descrizione;}
double articolo::getPrezzo()const{return prezzo;}
QString articolo::getStrPrezzo()const{return QString::number(prezzo);}
int articolo::getQuantita()const{return quantita;}
QString articolo::getStrQuantita()const{return QString::number(quantita);}
bool articolo::isPremium()const{return premium;}
QString articolo::strIsPremium()const{QString tmp="falso"; if(premium)tmp="vero"; return tmp;}

void articolo::setId(const QString &i){idArt=i;}
void articolo::setNomeA(const QString &n){nomeArt=n;}
void articolo::setDesc(const QString &d){descrizione=d;}
void articolo::setPrezzo(const double p){prezzo=p;}
void articolo::setQuantita(const int q){quantita=q;}
void articolo::setPremium(const bool pr){premium=pr;}
