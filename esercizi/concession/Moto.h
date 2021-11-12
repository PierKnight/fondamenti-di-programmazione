#ifndef MOTO_H
#define MOTO_H

#include "Veicolo.h"

class Moto : public Veicolo
{
    public:
    Moto(string _targa,float _prezzo,string _casa,string _nome):Veicolo(_targa,_prezzo,_casa,_nome){}
    
    string getTipoVeicolo() const
    {
        return "moto";
    }

    float getPrezzo() const
    {
        float p = Veicolo::getPrezzo();
        if(p <= 7000)
           p -= (p * 3.0) / 100.0;
        else if(p <= 15000)
           p -= (p * 7.5) / 100.0;  
        return p;
    }

    Moto* clone() const
    {
        return new Moto(*this);
    }

};

#endif