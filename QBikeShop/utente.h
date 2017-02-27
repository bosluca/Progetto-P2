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
    datiCarta(QString n, QString c,QString i):numCarta(n),cvc(c),intestatario(i) {}
    static datiCarta* getDati(QXmlStreamReader&); //Lettura da database
  QString getNumCarta()const;
    QString getCvc()const;
    QString getIntest()const;

    void setNumC(const QString& n);
    void setCvc(const QString& c);
    void setIntest(const QString& i);




#endif // UTENTE_H
