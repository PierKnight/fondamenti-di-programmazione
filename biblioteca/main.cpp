#include <iostream>
using namespace std;
#include "Libro.h"
#include "Cliente.h"
#include "Biblioteca.h"


unsigned int Libro::contatore = 10000;
unsigned int Cliente::contatore = 10000;

int main()
{

    Libro libro1("Il mare della bellezza","Pietori");
    Libro libro2("L'oscurita eterna","Mondadori");
    Libro libro3("Cosa c'e dopo la morte","Mondadori");
   
    Cliente cliente("Piero","PRPRDIHT");
    Cliente cliente2("Piero","AASAJr");
   

    Biblioteca biblioteca;


    biblioteca.aggiungereCliente(cliente);
    biblioteca.aggiungereCliente(cliente2);

    biblioteca.presta("PRPRDIHT",libro3);
    biblioteca.presta("AASAJr",libro1);

    biblioteca.aggiungereLibro(libro1);
    biblioteca.aggiungereLibro(libro2);
    biblioteca.aggiungereLibro(libro3);

    biblioteca.infoClienti();
    biblioteca.infoLibri();
    

 
    return 0;
}