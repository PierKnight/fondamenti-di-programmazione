#ifndef AUTO_H
#define AUTO_H

#include "Veicolo.h"

class Automobile : public Veicolo
{
    public:
    Automobile(string _targa,float _prezzo,string _casa,string _nome):Veicolo(_targa,_prezzo,_casa,_nome){}
    
    string getTipoVeicolo() const
    {
        return "automobile";
    }

    float getPrezzo() const
    {
        float p = Veicolo::getPrezzo();
        if(p <= 10000)
           p -= (p * 5.0) / 100.0;
        else if(p <= 20000)
           p -= (p * 10.0) / 100.0;  
        return p;
    }

    Automobile* clone() const
    {
        return new Automobile(*this);
    }

};

#endif