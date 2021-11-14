#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona 
{
    
    private:
    string codice_fiscale,nome,cognome;
    
    public:
    enum Impiego {Studente,Professore};

    Persona(string cf,string _nome,string _cognome): codice_fiscale(cf),nome(_nome),cognome(_cognome){}

    //getters
    string getCodiceFiscale() const {return codice_fiscale;}
    string getNome() const {return nome;}
    string getCognome() const {return cognome;}

    virtual float getTariffaMensa() const = 0;
    virtual float getReddito() const = 0;
    virtual Impiego getImpiego() const = 0;
    virtual Persona* newCopy() const = 0;

    string getImpiegoStr() const
    {
    switch (getImpiego())
    {
    case Studente:
        return "Studente";
        break;
    case Professore:
        return "Professore";
        break;
    default:
        return "Barbone senza un quattrino";
        break;
     }
    }

    virtual void print(ostream& out) const
    {
        out<<"Codice Fiscale: "<<codice_fiscale<<", ";
        out<<"Nome: "<<nome<<", ";
        out<<"Impiego: "<<getImpiegoStr()<<", ";
        out<<"Cognome: "<<cognome;
    }

    friend ostream& operator<<(ostream& out,Persona& p)
    {
        p.print(out);
        return out;
    }

};

#endif