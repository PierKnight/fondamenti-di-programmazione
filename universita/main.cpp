
#include "AnagraficaUniversitaria.h"
#include "Mensa.h"

int main()
{
    AnagraficaUniversitaria anagrafica;

    anagrafica.aggiungiStudente("feiurh3r4","Pierluigi","Altimari",100034434);
    anagrafica.aggiungiProfessore("eett","Mario","Alviano",344);


    Mensa mensa;

    Persona* persona = anagrafica.getPersona("feiurh3r4");

    mensa.accesso(persona);
    cout<<"Totale Prezzo: "<<mensa.calcolaIncassoGiornaliero()<<"$";

    return 0;
}