#include <iostream>
#include "GestoreDipendenti.h"

using namespace std;


int main()
{
    Dipendente dipendente1("0","Pero","Rossi",400);
    Dipendente dipendente2("1","Luigi","Verdi",500); 
    Dipendente dipendente3("0","Luigi","Verdi",500);  
    GestoreDipendenti gestore;

    gestore.aggiungiDipendente(dipendente1);
    gestore.aggiungiDipendente(dipendente2);
    gestore.aggiungiDipendente(dipendente3);

    cout<<"Totale Costo Stipendi: "<<gestore.calcolaCostiDipendenti()<<endl;

    gestore.stampa();

    return 0;
}