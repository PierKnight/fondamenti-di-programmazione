#include <iostream>
#include <string>
#include "GestorePrenotazioni.h"
using namespace std;

int main()
{
    GestorePrenotazioni gestore;

    gestore.aggiungiPrenotazione(1,codiciPosti[0]);
    gestore.aggiungiPrenotazione(1,codiciPosti[1]);
    gestore.aggiungiPrenotazione(43,codiciPosti[1]);
    gestore.ordinaPrenotazioni();

    for(int i = 0;i < 10;i++)
    gestore.stampaPrenotazioni(codiciPosti[i]);


    return 0;
}