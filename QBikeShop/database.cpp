#include "database.h"
//QString utentidatabase::fileutenti = "../Progetto/utentiDb.xml";
//QString articolidatabase::filearticoli = "../Progetto/articoliDb.xml";

utentidatabase::utentidatabase(){
    Load();
}
utentidatabase::~utentidatabase(){
    Close();
    contenitore::iteratore it=usDB.begin();
    for(;it!=usDB.end();++it){
        QString tmp=it.getUtentiIT()->getUsUname();
        rimuoviUtente(tmp);
    }
}

void utentidatabase::togli(const QString &uname){
    contenitore::iteratore it=usDB.begin();
    for(;it!=usDB.end();++it){
        if(it.getUtentiIT()->getUsUname()==uname)
            usDB.RimUtente(*it);
    }
}

void utentidatabase::rimuoviUtente(const QString &uname){
    togli(uname);
}

contenitore::iteratore utentidatabase::begin(){return usDB.begin();}
contenitore::iteratore utentidatabase::end(){return usDB.end();}

void utentidatabase::Load(){

}


