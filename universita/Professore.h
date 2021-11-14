#ifndef PROF_H
#define PROF_H

#include "Persona.h"

class Professore : public Persona
{
    private:
    float reddito;

    public:
    Professore(string cf,string _nome,string _cognome,float reddito): Persona(cf,_nome,_cognome)
    {
        this -> reddito = reddito;
    }

    float getTariffaMensa() const
    {
        if(getReddito() <= 30000)
        {
            return 2.5;
        }
        else if(getReddito() <= 40000)
        {
            return 3.5;
        }
        return 5.0;
    }

    float getReddito() const
    {
        return reddito;
    }

    Impiego getImpiego() const
    {
        return Persona::Professore;
    }

    void print(ostream& out) const
    {
        Persona::print(out);
        out<<", Reddito: "<<reddito<<endl;
    }

    Persona* newCopy() const
    {
        return new Professore(*this);
    }

};

#endif