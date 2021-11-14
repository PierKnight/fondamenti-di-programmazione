#ifndef ANA_UNI_H
#define ANA_UNI_H

#include "Persona.h"
#include "Studente.h"
#include "Professore.h"
#include "GestorePersone.h"

class AnagraficaUniversitaria : public GestorePersone
{

    public:
    bool aggiungiStudente(string codiceFiscale, string nome, string cognome,float isee);
    bool aggiungiProfessore(string codiceFiscale, string nome, string cognome,float reddito);
    Persona* getPersona(string codiceFiscale) const;

};


bool AnagraficaUniversitaria::aggiungiStudente(string codiceFiscale, string nome, string cognome,float isee)
{
    if(persone.find(codiceFiscale) == persone.end())
    {
        persone.insert({codiceFiscale,new Studente(codiceFiscale,nome,cognome,isee)});
        return true;
    }
    cout<<"Persona gia' presente con stesso codice fiscale"<<endl;
    return false;
}

bool AnagraficaUniversitaria::aggiungiProfessore(string codiceFiscale, string nome, string cognome,float reddito)
{
    if(persone.find(codiceFiscale) == persone.end())
    {
        persone.insert({codiceFiscale,new Professore(codiceFiscale,nome,cognome,reddito)});
        return true;
    }
    cout<<"Persona gia' presente con stesso codice fiscale"<<endl;
    return false;
}

Persona* AnagraficaUniversitaria::getPersona(string codice_fiscale) const
{
    unordered_map<string,Persona*>::const_iterator pos = persone.find(codice_fiscale);

    if(pos != persone.end())
        return (*pos).second;
    return nullptr;
}



#endif