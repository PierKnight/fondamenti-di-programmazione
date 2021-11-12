#ifndef GESTORE_VEIC_H
#define GESTORE_VEIC_H

#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"
#include <iostream>
#include <list>

class GestoreVeicoli
{
    private:
    list<Veicolo*> veicoli;

    
    void aggiungereVeicolo(Veicolo* veicolo)
    {
        for(auto pos = veicoli.begin();pos != veicoli.end();pos++)
        {
            if((**pos).getTarga() == veicolo -> getTarga())
            {
                cout<<"LA TARGA E' GIA' PRESENTE!!!"<<endl;
                return;
            }
        }
        veicoli.push_back(veicolo);

    }

    void clear()
    {
        while(!veicoli.empty())
        {
            delete veicoli.back();
            veicoli.pop_back();
        }
    }

    public:
    GestoreVeicoli()
    {

    }

    ~GestoreVeicoli()
    {
        clear();
    }

    GestoreVeicoli& operator=(const GestoreVeicoli& other)
    {
        clear();
        for(auto pos = other.veicoli.begin();pos != other.veicoli.end();pos++)
              veicoli.push_back((**pos).clone());
        return *this;
    }

    void aggiungiAutomobile(string targa,float prezzo,string casa,string nome)
    {
        Automobile* autom = new Automobile(targa,prezzo,casa,nome);
        aggiungereVeicolo(autom);
    }

    void aggiungiMoto(string targa,float prezzo,string casa,string nome)
    {
        Moto* moto = new Moto(targa,prezzo,casa,nome);
        aggiungereVeicolo(moto);
    }

};

#endif