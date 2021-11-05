#ifndef GESTORE_P_H
#define GESTORE_P_H

#include <iostream>
#include <list>
#include "Prenotazione.h"
#include <ctime>
using namespace std;

static string codiciPosti[10]{"a0001","b0002","c0003","d0004","e0005","f0006","g0007","h0008","i0009","z00010"};

class GestorePrenotazioni
{
    private: 
       int postiDisponibili[10]{2,4,5,6,7,2,2,2,2,3};
       list<Prenotazione*> prenotazioni;
       

    public:
       GestorePrenotazioni();
       GestorePrenotazioni(const GestorePrenotazioni&);
       ~GestorePrenotazioni();
       GestorePrenotazioni& operator=(const GestorePrenotazioni& other);

       bool esistePrenotazione(int numero);
       bool aggiungiPrenotazione(int posti, string codice);
       bool rimuoviPrenotazione(int  numero); 
       void stampaPrenotazioni(string codice) const;
       void ordinaPrenotazioni(); 
};


GestorePrenotazioni::GestorePrenotazioni()
{
   //inizializziamo un random generator con seed 0;
   srand(time(0));
}
GestorePrenotazioni::GestorePrenotazioni(const GestorePrenotazioni& g)
{
   srand(time(0));
   for(int i = 0;i < 10;i++)
       postiDisponibili[i] = g.postiDisponibili[i];

   for(auto pos = g.prenotazioni.begin(); pos != g.prenotazioni.end();pos++)
      aggiungiPrenotazione((**pos).getPosti(),(**pos).getCodice());
}

//distruttore mucho importante
GestorePrenotazioni::~GestorePrenotazioni()
{
    for(auto pos = prenotazioni.begin(); pos != prenotazioni.end();pos++)
       delete *pos;
}

GestorePrenotazioni& GestorePrenotazioni::operator=(const GestorePrenotazioni& o)
{
   prenotazioni.clear();
   for(int i = 0;i < 10;i++)
       postiDisponibili[i] = o.postiDisponibili[i];

   for(auto pos = o.prenotazioni.begin(); pos != o.prenotazioni.end();pos++)
      aggiungiPrenotazione((**pos).getPosti(),(**pos).getCodice());

   return *this;

}

bool GestorePrenotazioni::esistePrenotazione(int numero)
{
   for(auto pos = prenotazioni.begin(); pos != prenotazioni.end();pos++)
   {
      if((**pos).getNumero() == numero)
          return true;
   }
   return false;
}



bool GestorePrenotazioni::aggiungiPrenotazione(int posti,string codice)
{
   for(int i = 0;i < 10;i++)
   {
      if(codiciPosti[i] == codice)
      {
         int numeroPosti = postiDisponibili[i];
         if(numeroPosti >= posti)
         {
            int numero = rand() % 10000;
            while(esistePrenotazione(numero))
                numero = rand() % 10000;
               
            Prenotazione* prenotazione = new Prenotazione(numero,posti,codice);
            prenotazioni.push_back(prenotazione);
            postiDisponibili[i] -= posti;
            return true;
         }
         return false;
      }
   }

   return false;

}

bool GestorePrenotazioni::rimuoviPrenotazione(int numero)
{
   for(auto pos = prenotazioni.begin(); pos != prenotazioni.end();pos++)
   {
      if((**pos).getNumero() == numero)
      {
         for(int i = 0;i < 10;i++)
         {
            if((**pos).getCodice() == codiciPosti[i])
            {
               codiciPosti[i] += (**pos).getPosti();
               delete *pos;
               prenotazioni.erase(pos);
               return true;
            }
         }
      }
   }

   return false;
}


void GestorePrenotazioni::stampaPrenotazioni(string codice) const
{
   if(prenotazioni.empty())
   {
      cout<<"Non e' presente alcuna prenotazione."<<endl;
      return;
   }

   for(auto pos = prenotazioni.begin(); pos != prenotazioni.end();pos++)
   {
      if((**pos).getCodice() == codice)
      {
         cout<<"-Prenotazione numero: \""<<(**pos).getNumero()<<"\", Posti occupati: "<<(**pos).getPosti()<<endl;
      }
   }
}


//se ritorna true vuol dire che p1 precede p2, altrimenti no
bool ordinamento(Prenotazione* p1,Prenotazione* p2)
{
   
   if((*p1).getCodice()[0] == 'a')
       return true;
   if((*p2).getCodice()[0] == 'a')
       return false;
   if((*p1).getCodice()[0] == 'b')
       return true;
   if((*p2).getCodice()[0] == 'b')
       return false;
   if((*p1).getCodice()[0] == 'c')
       return true;
   if((*p2).getCodice()[0] == 'c')
       return false;
   
   
   return p1 -> getNumero() < p2 -> getNumero();

}



void GestorePrenotazioni::ordinaPrenotazioni()
{
   prenotazioni.sort(ordinamento);
}






#endif