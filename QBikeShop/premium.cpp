#include "premium.h"

QString premium::classeUtente()const{return "Premium";}

QString premium::stampaClasseUtente()const{QString stampa="Come utente premium hai accesso a tutti i nostri prodotti"; return stampa;}

void premium::regClasse(QXmlStreamWriter &xmlWriter) const{
    xmlWriter.writeTextElement("Classe","Premium");
}

bool premium::ricercaArticolo(const articolo *art, const QString &ricerca) const{
    if(art->getNomeA().contains(ricerca,Qt::CaseInsensitive) || art->getDesc().contains(ricerca,Qt::CaseInsensitive))
        return true;
    return false;
}

