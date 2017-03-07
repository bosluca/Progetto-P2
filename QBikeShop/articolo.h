#ifndef ARTICOLO_H
#define ARTICOLO_H
#include<QString>

class articolo{
private:
    QString idArt;
    QString nomeArt;
    QString descrizione;
    double prezzo;
    int quantita;
    bool premium;

public:
    articolo(const QString& id="N/A",const QString& n="N/A",const QString& d="N/A",const double p=-1,const int q=-1,const bool pr=0);

    QString getId()const;
    QString getNomeA()const;
    QString getDesc()const;
    double getPrezzo()const;
    QString getStrPrezzo()const;
    int getQuantita()const;
    QString getStrQuantita()const;
    bool isPremium()const;
    QString strIsPremium()const;

    void setId(const QString& i="N/A");
    void setNomeA(const QString& n="N/A");
    void setDesc(const QString& d="N/A");
    void setPrezzo(const double p=-1);
    void setQuantita(const int q=-1);
    bool setPremium(const bool pr=0);
};

#endif // ARTICOLO_H
