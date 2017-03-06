#include "base.h"

QString base::classeUtente()const{return "Base";}

QString base::stampaClasseUtente()const{QString stampa="Come utente base hai accesso ad un numero limitato di prodotti";return stampa;}

void base::regClasse(QXmlStreamWriter &xmlWriter) const{
    xmlWriter.writeTextElement("Classe","Base");
}

bool base::ricercaArticolo(const articolo *art, const QString &ricerca) const{
    if(art->getNomeA().contains(ricerca, Qt::CaseInsensitive)&&!(art->isPremium()))
        return true; //articolo non premium trovato
    return false; //ricerca fallita
}

