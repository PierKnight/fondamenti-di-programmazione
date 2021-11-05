#ifndef APPUNT_H
#define APPUNT_H

#include <iostream>
#include <string>

class Prenotazione
{
   private:
   int numero;
   int posti;
   std::string codice;


   public:
   Prenotazione(int a,int b,std::string c):numero(a),posti(b),codice(c){}

   //getters
   int getNumero() const{return numero;}
   int getPosti()  const{return posti;}
   std::string getCodice()  const{return codice;}

    friend std::ostream& operator<<(std::ostream& os,const Prenotazione& p)
    {
        os<<"Numero: "<<p.numero<<std::endl;
        os<<"Posti: "<<p.posti<<std::endl;
        os<<"Codice: "<<p.codice<<std::endl;
        return os;
    }


};

#endif