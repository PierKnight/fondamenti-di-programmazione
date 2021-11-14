#ifndef MENSA_H
#define MENSA_H

#include "GestorePersone.h"

class Mensa : public GestorePersone
{
    public:
    void accesso(Persona* p);
    float calcolaIncassoGiornaliero() const;
    void nuovoGiorno();
};


void Mensa::accesso(Persona* p)
{
    
    if(persone.find(p -> getCodiceFiscale()) == persone.end())
    {
        persone[p -> getCodiceFiscale()] = p->newCopy();
    }
}

float Mensa::calcolaIncassoGiornaliero() const
{
    float incasso = 0;

    for(auto pos = persone.begin();pos != persone.end();++pos)
        incasso += (*pos).second -> getTariffaMensa();   
    return incasso;
}

void Mensa::nuovoGiorno()
{
    clear();
}

#endif