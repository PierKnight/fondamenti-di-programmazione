#ifndef GESTORE_H
#define GESTORE_H

#include <iostream>
#include <vector>
#include "Dipendente.h"

using namespace std;


class GestoreDipendenti
{
    private:
    vector<Dipendente> dipendenti;

    public:
    GestoreDipendenti(){}

    
    bool esisteDipendente(const string& id) const
    {
        for(int i = 0;i < dipendenti.size();i++)
            if(dipendenti[i].getId() == id)
                return true;
        return false;
    }


    bool aggiungiDipendente(Dipendente& d)
    {
        if(!esisteDipendente(d.getId()))
        {
             dipendenti.push_back(d);
             return true;
        }
        return false;
    }

    bool rimuoviDipendente(const string& id)
    {
        //remove semplicemente ordina le liste,mettendo il valore da eleminare a destra ,e poi con erase cancelliamo da quel punto a end
        //dipendenti.erase(remove(dipendenti.begin(),dipendenti.end(),dipendente),dipendenti.end());

        if(esisteDipendente(id))
         for(vector<Dipendente>::iterator pos = dipendenti.begin();pos != dipendenti.end();pos++)            
            if(pos -> getId() == id)
            {
                dipendenti.erase(pos);
                return true;
            }
        return false;
    }

    float calcolaCostiDipendenti() const
    {
        float totale = 0;

        for(int i = 0;i < dipendenti.size();i++)
              totale += dipendenti[i].getStipendio();
        return totale;
    }

    void stampa() const
    {
        cout<<"Totale Dipendenti: "<<dipendenti.size()<<endl;
    }

};

#endif