#ifndef STUDENTE_H
#define STUDENTE_H

#include "Persona.h"

class Studente : public Persona
{
    private:
    float isee;

    public:
    Studente(string cf,string _nome,string _cognome,float isee): Persona(cf,_nome,_cognome)
    {
        this -> isee = isee;
    }

    float getTariffaMensa() const
    {
        if(getReddito() <= 10000)
        {
            return 0;
        }
        else if(getReddito() <= 20000)
        {
            return 2.0;
        }
        else if(getReddito() <= 40000)
        {
            return 3.0;
        }
        return 4.0;
    }

    float getReddito() const
    {
        return isee;
    }

    Impiego getImpiego() const
    {
        return Persona::Studente;
    }

    void print(ostream& out) const
    {
        Persona::print(out);
        out<<", ISEE: "<<isee<<endl;
    }

    Persona* newCopy() const
    {
        return new Studente(*this);
    }

};

#endif